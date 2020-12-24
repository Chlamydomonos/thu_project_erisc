cd %1

for %%i in (image/*.bmp) do copy "%%i" %2images
copy image/image.imgcfg %2images
copy vm.vmcfg %2