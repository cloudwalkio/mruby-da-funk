MRuby::Gem::Specification.new('mruby-da-funk') do |spec|
  spec.license = 'MIT'
  spec.authors = 'CloudWalk Developers'
  spec.version = "1.0.0"

  spec.cc.include_paths << "#{build.root}/lib/src"
  spec.objs << Dir.glob("#{dir}/lib/src/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  spec.rbfiles << Dir.glob("#{dir}/mrblib/*.rb")

  spec.add_dependency 'mruby-io'
  spec.add_dependency 'mruby-socket'
  spec.add_dependency 'mruby-time'
  spec.add_dependency 'mruby-context'
end
