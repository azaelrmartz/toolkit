ln -s ../Database.h Database.h 
ln -s ../DatabaseMySQL.c DatabaseMySQL.c
touch AUTHORS NEWS README ChangeLog

aclocal
autoconf
automake --add-missing
