project('rfidAdmin', 'cpp',
  version : '1.01.0',
  default_options : ['warning_level=0', 'cpp_std=c++17']
  )
APP_NAME = 'rfidAdmin'

app_env = ['-DAPP_ENV="DEBUG"', '-DSPDLOG_LEVEL="debug"', '-DRFID_SERVER_ADDR="192.168.1.201"', '-DRFID_SERVER_PORT=8080']


gnome = import('gnome')
src_dir = meson.current_source_dir()


# resources compilation
schemas = gnome.compile_schemas(depend_files: 'rfid.opaic.assignment.sep.nz.gschema.xml')
epoxy = dependency('epoxy')

if epoxy.found()
  app_resources = gnome.compile_resources('app-resources',
    '@0@.gresource.xml'.format(APP_NAME),
    source_dir: join_paths(src_dir, 'assets'),
    install: false
  )


extra_link_args = []


# project files
c_files = [
  'src/main.cc',
  'src/LoginWindow.cc',
  'src/App.cc',
  'src/BaseWindow.cc',
  'src/NetworkClient.cc',
  'src/InputDialog.cc',
  'src/ControlsWindow.cc'
]

executable(APP_NAME,
           c_files,
           app_resources,
           schemas,
           dependencies : [
              dependency('gtkmm-4.0'),
              dependency('spdlog'),
              dependency('epoxy')
              ],
           cpp_args: app_env,
           link_args: extra_link_args,
           install : true,
           
            # implicit_include_directories: false,
            # win_subsystem: 'windows',
            # build_by_default: build_demos,
            # link_args: gui_app_ldflags
           )
endif

# bundle

if host_machine.system() == 'darwin'
  install_data('app_entry.sh',
  install_dir : 'Contents/MacOS')

  install_data('icon.icns',
  install_dir : 'Contents/Resources')

  install_data('Info.plist',
  install_dir : 'Contents')

  meson.add_install_script('osx_bundler.sh')
endif

# if host_machine.system() == 'linux'
#   install_data('myapp.sh', install_dir : '.')
#   meson.add_install_script('linux_bundler.sh')
# endif

# extra_link_args = []

# if host_machine.system() == 'windows'
#   str = '-I@0@/@1@'.format(meson.current_build_dir(), 'SDL2-2.0.3/include')
#   add_global_arguments(str, language : 'cpp')
#   extra_link_args = ['/SUBSYSTEM:CONSOLE', 'SDL2main.lib', 'SDL2.lib']
# endif