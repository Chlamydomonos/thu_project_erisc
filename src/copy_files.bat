cd %1
md %2images
cd image
for %%i in (*.bmp) do copy "%%i" %2images
copy image.imgcfg %2images
cd %1
copy vm.vmcfg %2