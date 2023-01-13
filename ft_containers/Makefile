CC = c++
VERSION = -std=c++98
CFLAGS =  -Wall -Wextra -Werror

src = src/main.cpp 

all: $(src) src/*.hpp
	$(CC) $(VERSION) -D LIB=ft $(CFLAGS)  -o ft $(src) 
	$(CC) $(VERSION) -D LIB=std $(CFLAGS)  -o std $(src) 

exec: all
	@bash -c './ft > ft_out.txt'
	@bash -c './std > std_out.txt'
	@bash -c 'echo  -e "\033[0;33m" ---------------------  std  ---------------------   "\033[0;37m"'
	@bash -c 'cat std_out.txt'
	@bash -c 'echo  -e "\033[0;32m" ---------------------  ft  ---------------------   "\033[0;37m"'
	@bash -c 'cat ft_out.txt'
	@bash -c 'echo  -e "\033[0;34m" ---------------------  diff  ---------------------   "\033[0;37m"'
	@bash -c 'diff ft_out.txt std_out.txt && echo "OK" || echo -e "\033[0;31m" "KO" "\033[0;37m"'
	@bash -c 'echo  -e "\033[0;34m" ------------------------------------------------"\033[0;37m"'