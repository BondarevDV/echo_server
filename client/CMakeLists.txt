cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

include_directories(lib)									
add_executable(bdv_client client.c erproc.c)	
