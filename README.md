# RFID Admin App

===
Gnome C++ application that implements RFID MFRC522 simple interface


- dependencies
    * gtkmm4
    * spdlog
    * epoxy

* build  - using **meson build lib
    - MacOS

      https://mesonbuild.com/Creating-OSX-packages.html
    ```
    # helper script
    ./build_scripts/build_osx_package.sh
    ```
    Signing is required manually for distribution.
    - Windows

    ```
    #TODO
    ```
    - Linux

    ```
    #TODO
    ```
---
build treats:

### create MacOs icon.icns
```
# manually
sips -z 512 512 input_img.png --out icon_512x512.png
mkdir icon.iconset
iconutil -c icns icon.iconset
```
```
# or helper script
./generate_icons.sh iconname.png iconfoldername.iconset
```

### create DMG template for build

```
hdiutil create -size 100m -fs 'HFS+' -volname 'My App' -type UDIF -layout SPUD template.dmg

gzip -c template.dmg > template.dmg.gz

```

## build deps
* dylibbundler
* meson
* python>=3.7
* iconutil