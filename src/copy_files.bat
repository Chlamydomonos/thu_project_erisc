md %2
for %%i in (%1src\image\*.bmp) do (copy "%%i" %2images)
for %%i in (%1src\image\*.imgcfg) do (copy "%%i" %2images)