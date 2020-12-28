cd %1
md "../qt_build/images"
cd image
for %%i in (*.bmp) do copy "%%i" "../../qt_build/images"
copy "image.imgcfg" "../../qt_build/images"
cd ..
copy "vm.vmcfg" "../qt_build"