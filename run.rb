require 'erb'
require 'fileutils'
require 'yaml'

ARG_PATH_OPT_LIST = ARGV[0] # yaml file for getopt definition

PATH_SETTINGS = 'settings.yml'.freeze
NAME_ERB_LISTOPTOBJ_H = 'XCListOptObject.h.erb'.freeze
NAME_ERB_LISTOPTOBJ_CPP = 'XCListOptObject.cpp.erb'.freeze

YAML_SETTINGS = YAML.load_file(PATH_SETTINGS)
YAML_OPT_LIST = YAML.load_file(ARG_PATH_OPT_LIST)

CLASS_LIST = []

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

def camelize(arg_name)
   return arg_name.tr('-', '_').split('_').map(&:capitalize).join
end

def getClassName(arg_key, arg_hash)
  case arg_hash['type']
  when 'string' then
    if arg_hash.key?('list')
      return camelize(arg_key)
    end
  end
  return camelize(arg_hash['type'])
end

def makeOptList(arg_name, arg_list_enum)
  name_class = arg_name
  list_enum = arg_list_enum

  path_h_erb = 'template/XCOptStringXxx.h.erb'
  path_h = "dist/XCOpt#{name_class}.h"
  erb = ERB.new(IO.read(path_h_erb), nil, '-')
  File.open(path_h, 'w') do |f|
    f.write(erb.result(binding))
    puts "#{path_h_erb} -> #{path_h}"
  end
  path_cpp_erb = 'template/XCOptStringXxx.cpp.erb'
  path_cpp = "dist/XCOpt#{name_class}.cpp"
  erb = ERB.new(IO.read(path_cpp_erb), nil, '-')
  File.open(path_cpp, 'w') do |f|
    f.write(erb.result(binding))
    puts "#{path_cpp_erb} -> #{path_cpp}"
  end
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
  val['name'] = 'm_cOpt' + camelize(key)
  val['class'] = 'XCOpt' + getClassName(key, val)
  CLASS_LIST.push(val['class'])
end
CLASS_LIST.uniq!

YAML_OPT_LIST['options'].each do |key, val|
  if val.has_key?('list')
    makeOptList(camelize(key), val['list'])
  end
end

# auto-generate (List of OptObject)
run("template/#{NAME_ERB_LISTOPTOBJ_H}", "dist/" + File.basename(NAME_ERB_LISTOPTOBJ_H, '.erb'))
run("template/#{NAME_ERB_LISTOPTOBJ_CPP}", "dist/" + File.basename(NAME_ERB_LISTOPTOBJ_CPP, '.erb'))

FileUtils.cp(Dir.glob("assets/*"), "dist")
