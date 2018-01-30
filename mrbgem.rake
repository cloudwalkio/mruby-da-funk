MRuby::Gem::Specification.new('mruby-da-funk') do |spec|
  spec.license = 'MIT'
  spec.authors = 'CloudWalk Developers'
  spec.version = "1.0.0"

  spec.cc.include_paths << "#{build.root}/lib/src"
  spec.objs = Dir.glob("#{dir}/lib/src/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }

  # Add compile flags
  # spec.cc.flags << ''

  # Add cflags to all
  # spec.mruby.cc.flags << '-g'

  # Add libraries
  # spec.linker.libraries << 'external_lib'

  # Default build files
  spec.rbfiles = Dir.glob("#{dir}/mrblib/*.rb")
  # spec.objs = Dir.glob("#{dir}/src/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  # spec.test_rbfiles = Dir.glob("#{dir}/test/*.rb")
  # spec.test_objs = Dir.glob("#{dir}/test/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  # spec.test_preload = 'test/assert.rb'

  # Values accessible as TEST_ARGS inside test scripts
  # spec.test_args = {'tmp_dir' => Dir::tmpdir}
  spec.add_dependency 'mruby-io'
  spec.add_dependency 'mruby-socket'
  spec.add_dependency 'mruby-time'
  spec.add_dependency 'mruby-context'
end
