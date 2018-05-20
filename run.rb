require 'erb'
require 'fileutils'
require 'yaml'

ARG_PATH_OPT_LIST = ARGV[0] # yaml file for getopt definition

PATH_SETTINGS = 'settings.yml'.freeze
NAME_ERB_LISTOPTOBJ_H = 'XCListOptObject.h.erb'.freeze
NAME_ERB_LISTOPTOBJ_CPP = 'XCListOptObject.cpp.erb'.freeze

YAML_SETTINGS = YAML.load_file(PATH_SETTINGS)
YAML_OPT_LIST = YAML.load_file(ARG_PATH_OPT_LIST)

def help
  puts 'help'
end

def run(arg_path_erb, arg_path_output)
  erb = ERB.new(IO.read(arg_path_erb), nil, '-')
  File.open(arg_path_output, 'w') do |f|
    f.write(erb.result(binding))
    puts "#{arg_path_erb} -> #{arg_path_output}"
  end
end

def makeVariableName(arg_name)
   return 'm_cOpt' + arg_name.tr('-', '_').split('_').map(&:capitalize).join
end

# ==================================

unless File.exist?(ARG_PATH_OPT_LIST)
  help
  exit 0
end

indent = 0;
YAML_OPT_LIST['options'].each do |key, val|
  if indent < key.size
    indent = key.size
  end
end
INDENT = 2 + indent + 4;

YAML_OPT_LIST['options'].each do |key, val|
  val['name'] = makeVariableName(key)
  args = "\"#{key}\", \"#{val['description']}\""
  case val['type']
  when 'int32'
    args += ", #{val['base']}"
  end
  val['constructor'] = args
end

# auto-generate (List of OptObject)
run("template/#{NAME_ERB_LISTOPTOBJ_H}", "dist/" + File.basename(NAME_ERB_LISTOPTOBJ_H, '.erb'))
run("template/#{NAME_ERB_LISTOPTOBJ_CPP}", "dist/" + File.basename(NAME_ERB_LISTOPTOBJ_CPP, '.erb'))

FileUtils.cp(Dir.glob("assets/*"), "dist")
