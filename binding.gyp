{
  'variables': {
    'platform': '<(OS)',
    'build_arch': '<!(node -p "process.arch")',
    'build_win_platform': '<!(node -p "process.arch==\'ia32\'?\'Win32\':process.arch")',
  },
  'conditions': [
    # Replace gyp platform with node platform, blech
    ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
    ['platform == "win"', {'variables': {'platform': 'win32'}}],
  ],
  'targets': [
    {
      'target_name': 'native-glu',
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'sources': [
        'src/glu.cc'
      ],
      'defines' : ['NAPI_DISABLE_CPP_EXCEPTIONS','UNICODE'],
      'libraries': ['glu32'],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'library_dirs' : [],
    },
    {
      "target_name": "copy_modules",
      "type":"none",
      "dependencies" : [ "native-glu" ],
      "copies":[
        {
          'destination': '<(module_root_dir)\\bin\\<(platform)\\<(target_arch)',
          'files': [
            '<(module_root_dir)\\build\\Release\\native-glu.node',
          ]
        },
        {
          'destination': '<(module_root_dir)\\dist',
          'files': [
            '<(module_root_dir)\\src\\types\\index.d.ts',
          ]
        },
       {
          'destination': '<(module_root_dir)\\..\\node-native-opengl-examples\\node_modules\\@devzolo\\node-native-glu\\bin\\<(platform)\\<(target_arch)',
          'files': [
            '<(module_root_dir)\\build\\Release\\native-glu.node',
          ]
        },
        {
          'destination': '<(module_root_dir)\\..\\node-native-opengl-examples\\node_modules\\@devzolo\\node-native-glu\\dist',
          'files': [
            '<(module_root_dir)\\src\\types\\index.d.ts',
          ]
        }
      ]
    }
  ]
}
