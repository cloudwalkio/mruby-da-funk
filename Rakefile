require 'fileutils'

MRUBY_DA_FUNK_ROOT       = ENV["MRUBY_DA_FUNK_ROOT"] || File.join(File.dirname(File.expand_path(__FILE__)))
MRUBY_DA_FUNK_MRUBY_ROOT = File.join(MRUBY_DA_FUNK_ROOT, "mruby")
MRUBY_DA_FUNK_MAIN_ROOT  = File.join(MRUBY_DA_FUNK_ROOT, "lib", "main")
MRUBY_DA_FUNK_ENV        = ENV["MRUBY_DA_FUNK_ENV"] == "production" ? "production" : "development"
SIGNATURE                = ENV["SIGNATURE"] == "production" ? "production" : "mockup"
MRUBY_VERSION            = "1.3.0"

require File.join(MRUBY_DA_FUNK_ROOT, 'build_config.rb')
file :mruby do
  sh "git clone --branch 1.3.0 https://github.com/mruby/mruby.git "
end

if ENV["MRUBY_CONFIG"] == File.expand_path(__FILE__)
  MRuby::Build.new do |conf|
    if ENV['VisualStudioVersion']
      toolchain :visualcpp
    else
      toolchain :gcc
    end

    if RUBY_PLATFORM =~ /x86_64-linux/i
    elsif RUBY_PLATFORM =~ /linux/i
      conf.cc.flags << %w(-msse2)
      conf.linker.flags << %w(-msse2)
    end

    conf.gem :core => "mruby-bin-mirb"
    conf.gem :core => "mruby-bin-mruby"
    conf.gem :core => "mruby-bin-strip"

    enable_debug
  end

  # Define cross build settings
  MRuby::CrossBuild.new('device') do |conf|
    toolchain :gcc

    conf.cc.defines << %w(SHA256_DIGEST_LENGTH=32 SHA512_DIGEST_LENGTH=64 MRB_STACK_EXTEND_DOUBLING)

    if RUBY_PLATFORM =~ /x86_64-linux/i
    elsif RUBY_PLATFORM =~ /linux/i
      conf.cc.flags << %w(-msse2)
      conf.linker.flags << %w(-msse2)
    end

    gem_config(conf)
    enable_debug
  end
else
  task :default => :build

  desc "Execute Sample"
  task :execute => :build do
    FileUtils.cd File.join(MRUBY_DA_FUNK_ROOT, "out")
    exit sh("./sample")
  end

  desc "Setup env"
  task :env => :mruby do
    FileUtils.cd MRUBY_DA_FUNK_MRUBY_ROOT
    ENV["MRUBY_CONFIG"] = File.expand_path(__FILE__)
  end

  desc "Compile MRuby"
  task :build_mruby => :env do
    sh("rake")
  end

  desc "Compile Main and Create package"
  task :main_rb do
    FileUtils.cd MRUBY_DA_FUNK_MAIN_ROOT
    ENV["MRBC"] ||= File.join(MRUBY_DA_FUNK_MRUBY_ROOT, "bin", "mrbc")
    sh("bundle install")
    sh("bundle exec ruby -e 'Bundler.with_clean_env { system %( bundle exec rake ) }'")
    FileUtils.cd MRUBY_DA_FUNK_ROOT
    FileUtils.rm_rf "out"
    FileUtils.mkdir_p "out"
    FileUtils.cp_r File.join(MRUBY_DA_FUNK_MAIN_ROOT, "out", "main"), "out/"
    FileUtils.cp_r File.join(MRUBY_DA_FUNK_MAIN_ROOT, "out", "shared"), "out/"
    files = Dir[File.join(MRUBY_DA_FUNK_ROOT, "lib", "*")]
    files << File.join(MRUBY_DA_FUNK_ROOT, "lib", "env", "#{MRUBY_DA_FUNK_ENV}.rb")
    files_str = files.select{|p| File.file?(p) }.join(" ")
    File.open(File.join(MRUBY_DA_FUNK_ROOT, "out", "shared", "device.sig"), "wb") {|f| f.write("signer=#{SIGNATURE}") }
    sh("#{ENV["MRBC"]} -g -o #{File.join(MRUBY_DA_FUNK_ROOT, "out", "main", "platform.mrb")} #{files_str}")
  end

  desc "Compile src/main.c linking libmruby.a"
  task :build => [:build_mruby, :main_rb]

  desc "Compile src/main.c linking libmruby.a"
  task :main_c do
    FileUtils.cd MRUBY_DA_FUNK_ROOT
    sh("gcc src/main.c -o out/sample mruby/build/device/lib/libmruby.a -Imruby/include -lm")
  end

  desc "Clean"
  task :clean => :env do
    FileUtils.rm_rf File.join(MRUBY_DA_FUNK_ROOT, "out")
    exit sh("rake clean")
  end

  desc "Test"
  task :test => :env do
    exit sh("rake test")
  end

  desc "Setup Project and Submodules"
  task :setup do
    sh "git submodule update --init --recursive"
    exit
  end
end
