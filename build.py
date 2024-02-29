import os
import shutil
import re

def move_include_files(sdl2_dir):
    sdl2_include_dir = os.path.join(sdl2_dir, 'include')
    sdl2_include_sdl2_dir = os.path.join(sdl2_include_dir, 'SDL2')

    if not os.path.exists(sdl2_include_sdl2_dir):
        os.makedirs(sdl2_include_sdl2_dir)

    files = os.listdir(sdl2_include_dir)
    for file in files:
        if file != 'SDL2':
            shutil.move(os.path.join(sdl2_include_dir, file), os.path.join(sdl2_include_sdl2_dir, file))

# Example usage
move_include_files('./deps/SDL2')


def update_imgui_include(dir):
    imgui_dir = os.path.join(dir, 'imgui')
    imgui_files = [
        os.path.join(imgui_dir, 'backends', 'imgui_impl_sdl2.h'),
        os.path.join(imgui_dir, 'backends', 'imgui_impl_opengl3.h')
    ]

    for file_path in imgui_files:
        with open(file_path, 'r') as f:
            content = f.read()
        content = re.sub(r'#include "imgui\.h"', '#include "imgui/imgui.h"', content)
        with open(file_path, 'w') as f:
            f.write(content)
            
update_imgui_include('./deps/')