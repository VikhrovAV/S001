// S001.VikhrovAV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

    int main()

    {

        std::cout << "Hello World!\n";

        char s[256];

        char s1[256];

        char s2[512];

        char f[] = "%s";

        char fd[] = "%d\n";

        _asm {
                        //Читаем первую строку
            lea ebx, s

            push ebx

            lea ecx, f

            push ecx

            call scanf

            add esp, 8
                        //Читаем вторую строку
            lea ebx, s1

            push ebx

            lea ecx, f

            push ecx

            call scanf

            add esp, 8
                       //Заготавливаем цикл перезаписи для первой строки
            lea ebx, s

            mov ecx, -1

            dec ebx

            lea edx, s2

            dec edx
                       //Цикл для перезаписи первой строки
            b1 :
            inc ecx
                inc ebx
                inc edx
                mov al, [ebx]
                mov[edx], al
                cmp al, 0
                jnz b1

                            //Заготавливаем цикл перезаписи для первой строки
                lea ebx, s1

                dec edx

                dec ebx
                         //Цикл перезаписи второй строки
                b2 :
            inc edx
                inc ebx
                mov al, [ebx]
                mov[edx], al
                cmp al, 0
                jnz b2
                            //Вывод
                lea ebx, s2
                push ebx
                lea ecx, f
                push ecx
                call printf
                add esp, 8

        }

    }




