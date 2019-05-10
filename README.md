# Subject
You must recode the ls [-lRdrt] [FILE] command. Options can be given in different orders. It must be possible to pass a list of files/folders as parameters.

# Authorized functions
* opendir
* readdir
* closedir
* stat
* lstat
* write
* getpwuid
* getgrgid
* time
* ctime
* readlink
* malloc
* free
* perror
* strerror
* exit

# Building
$ make

# Usage
$ ./ls [-lRdrt] [file_path(s)]

# Mark
**11,5/20**
