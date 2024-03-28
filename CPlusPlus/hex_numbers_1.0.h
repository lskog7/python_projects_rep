//
// Created by user on 13.03.2024.
//

#ifndef MAIN_PROJECT_LONG_HEX_ARYTH_1_0_H
#define MAIN_PROJECT_LONG_HEX_ARYTH_1_0_H

#endif //MAIN_PROJECT_LONG_HEX_ARYTH_1_0_H

#include <iostream>
#include <string>
#include <limits>
#include <conio.h>
#include <cmath>

#define BASE 8
#define CLS (system("cls"))
#define RUSSIAN (setlocale(LC_ALL, ""))

void approve();

int factorial(int n);

class Oct_number
/* Класс "восьмеричное число".
 */
{
protected:

    // Атрибут - максимальное количество цифр в числе.
    int max_length{10};

    // Атрибут - указатель на массив с цифрами числа.
    // Массив, состоящий из '.', экивалентен числу 0.
    char *container;

    // Атрибут - показатель, является ли число отрицательным.
    bool is_negative;

public:
    Oct_number(bool state)
    /* Конструктор. Создает число типа Oct_number
     * Параметры:
     *   bool state : указывает, нужно ли иницализировать число вводом с клавиатуры.
     */
    {
        // Метка. Показывает, является ли введеное число корректным.
        bool not_okay{true};

        // Метки. Показывают, является ли очередной символ числом / минусом.
        bool c_is_number{false}, c_is_minus{false};

        // Вспомогательная переменная. Используется для заполнения массива container.
        unsigned j;

        // Вспомогательная переменная. Хранит в себе значение очередного ввода пользователя.
        std::string answer;

        // Инциализация container массивом длиной max_length.
        // По умолчанию все создаваемые числа положительны.
        this->container = new char[this->max_length];
        this->is_negative = false;

        // По умолчанию число равно нулю.
        for (int i = 0; i < this->max_length; i++)
        {
            this->container[i] = '.';
        }

        // Код ниже выполняется только в том случае, если для числа требуется явная инициализация
        // (когда пользователя просят явно ввести число).
        if (state)
        {
            // Ввод числа будет продолжаться до тех пор, пока не будет введено корректное восьмеричное число.
            while (not_okay)
            {
                // Начать заполнять массив container заново.
                j = 0;

                // Считать, что по началу число является правильным (до встречи с ошибкой).
                not_okay = false;

                std::cout << "Введите восьмеричное число: ";
                std::cin >> answer;

                // Сброс заполнения, если длина введенной строки превышает максимальную.
                if (answer.length() > this->max_length)
                {
                    std::cout << "Длина числа превышает максимальную. Число не было считано." << std::endl;
                    this->is_negative = false;
                    not_okay = true;
                    continue;
                }

                    // Если введеная строка представляет собой единственный ноль, то ничего не делать (выйти из цикла).
                    // (По умолчанию число инциализировано нулем).
                else if ((answer[0] == '0') && (answer.length() == 1))
                {
                    break;
                }

                else
                {
                    // Если не выполнились два предыдущих условия, то идет посимвольная проверка и запись
                    // строки answer в массив container.
                    for (auto c : answer)
                    {
                        // Является ли символ c допустимым для восьмеричной системы счисления числом?
                        c_is_number = ('0' <= c) && (c <= '0' + BASE - 1);

                        // Является ли символ с начальным минусом?
                        c_is_minus = (j == 0) && (c == '-');

                        // Если символ c не является допустимым числом или начальным минусом ИЛИ если символ c является
                        // нулем в начале всего числа, происходит сброс заполнения.
                        if (!(c_is_number || c_is_minus) || ((c == '0') && (j == 0)))
                        {
                            std::cout << "Введены некорректные символы. Число не было считано." << std::endl;
                            for (int i = 0; i < max_length; i++)
                            {
                                this->container[i] = '.';
                            }
                            this->is_negative = false;
                            not_okay = true;
                            break;
                        }
                        // Если символ c является начальным минусом, то объявить число отрицательным,
                        // не смещая порядок записи в массив container.
                        if (c_is_minus)
                        {
                            this->is_negative = true;
                        }

                            // В противном случае записать символ c в массив container и сдвинуть
                            // указатель j на следующую позицию.
                        else
                        {
                            this->container[j] = c;
                            j++;
                        }
                    }
                }
            }
        }
    }

    Oct_number(const Oct_number& object)
    /* Конструктор копирования. Создает число типа Extended_oct_number на основе другого числа типа Extended_oct_number.
     * Параметры:
     *   const Extended_oct_number& object : число, на базе которого создается новое число.
     */
    {

        // Удаление предыдущего динамического массива container.
        // Инциализация container массивом длиной max_length.
        delete[] this->container;
        this->container = new char[this->max_length];

        // Копирование всех знаков из массива container объекта object в
        // массив container текущего объекта.
        for (int i = 0; i < this->max_length; i++)
        {
            this->container[i] = object.container[i];
        }

        // Копирование атрибута is_negative объекта object
        // в атрибут is_negative текущего объекта.
        this->is_negative = object.is_negative;
    }

    void Change_number()
    /* Функция. Изменяет текущее число Oct_number на другое.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Нет
     */
    {
        // Метка. Показывает, является ли введеное число корректным.
        bool not_okay{true};

        // Метки. Показывают, является ли очередной символ числом / минусом.
        bool c_is_number{false}, c_is_minus{false};

        // Вспомогательная переменная. Используется для заполнения массива container.
        unsigned j;

        // Вспомогательная переменная. Хранит в себе значение очередного ввода пользователя.
        std::string answer;

        // Освобождение памяти от предыдущего значения числа.
        // Инциализация container массивом длиной max_length.
        // По умолчанию все создаваемые числа положительны.
        delete[] this->container;
        this->container = new char[max_length];
        this->is_negative = false;


        // По умолчанию число равно нулю.
        for (int i = 0; i < this->max_length; i++)
        {
            container[i] = '.';
        }

        // Ввод числа будет продолжаться до тех пор, пока не будет введено корректное восьмеричное число.
        while (not_okay)
        {
            // Начать заполнять массив container заново.
            j = 0;

            // Считать, что по началу число является правильным (до встречи с ошибкой).
            not_okay = false;

            std::cout << "Введите восьмеричное число: ";
            std::cin >> answer;

            // Сброс заполнения, если длина введенной строки превышает максимальную.
            if (answer.length() > this->max_length)
            {
                std::cout << "Длина числа превышает максимальную. Число не было считано." << std::endl;
                this->is_negative = false;
                not_okay = true;
                continue;
            }

                // Если введеная строка представляет собой единственный ноль, то ничего не делать (выйти из цикла).
                // (По умолчанию число инциализировано нулем).
            else if ((answer[0] == '0') && (answer.length() == 1))
            {
                break;
            }

            else
            {
                // Если не выполнились два предыдущих условия, то идет посимвольная проверка и запись
                // строки answer в массив container.
                for (auto c : answer)
                {
                    // Является ли символ c допустимым для восьмеричной системы счисления числом?
                    c_is_number = ('0' <= c) && (c <= '0' + BASE - 1);

                    // Является ли символ с начальным минусом?
                    c_is_minus = (j == 0) && (c == '-');

                    // Если символ c не является допустимым числом или начальным минусом ИЛИ если символ c является
                    // нулем в начале всего числа, происходит сброс заполнения.
                    if (!(c_is_number || c_is_minus) || ((c == '0') && (j == 0)))
                    {
                        std::cout << "Введены некорректные символы. Число не было считано." << std::endl;
                        for (int i = 0; i < max_length; i++)
                        {
                            this->container[i] = '.';
                        }
                        this->is_negative = false;
                        not_okay = true;
                        break;
                    }

                    // Если символ c является начальным минусом, то объявить число отрицательным,
                    // не смещая порядок записи в массив container.
                    if (c_is_minus)
                    {
                        this->is_negative = true;
                    }

                        // В противном случае записать символ c в массив container и сдвинуть
                        // указатель j на следующую позицию.
                    else
                    {
                        this->container[j] = c;
                        j++;
                    }
                }
            }
        }
    }

    void Set_zero()
    /* Функция. Обнуляет текущее число.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Нет
     */
    {
        // Массив container, содержащий только '.', считается равным нулю.
        for (int i = 0; i < max_length; i++)
        {
            this->container[i] = '.';
        }
    }

    void Print_number(bool state=true)
    /* Фукнция. Выводит число (Oct_number, Extended_oct_number) в поток вывода.
     * Параметры:
     *   bool state=true : указывает, нужно ли переходить на новую строку после вывода числа.
     * Возвращаемое значение:
     *   Нет
     */
    {
        // Если массив container хранит только точки, то выводится "0".
        if (this->container[0] == '.')
        {
            std::cout << "0";
        }

            // В противном случае число является не нулем.
        else
        {
            // Если число является отрицательным, то выводится знак "-".
            if (this->is_negative)
            {
                std::cout << '-';
            }

            // Цикл пробегается по массиву container и выводит каждый символ,
            // не являющийся точкой, в поток вывода. При первой встрече с
            // '.' печать числа прекращается (после '.' цифра идти не может).
            for (int i = 0; i < this->max_length; i++)
            {
                if (this->container[i] != '.')
                {
                    std::cout << this->container[i];
                }
                else
                {
                    break;
                }
            }
        }

        // Если указано перейти на новую строку, происходит переход.
        if (state)
        {
            std::cout << std::endl;
        }
    }

    void Print_for_equaution(bool result=false)
    /* Функция. Выводит число [Oct_number / Extended_oct_number] в поток вывода для уравнений.
     * Параметры:
     *   bool result=false : указывает, является ли выводимое число результатом операции.
     *                       Если число является результатом операции, то оно никогда не
     *                       берется в скобки.
     * Возвращаемое значение:
     *   Нет
     */
    {

        // Если число является результатом операции, то оно выводится
        // с переходом на новую строку.
        if (result)
        {
            this->Print_number();
        }

        else
        {
            // Если число является отрицательным, то оно обрамляется скобками.
            if (this->is_negative)
            {
                std::cout << "(";
            }

            // Вывод числа без перехода на новую строку.
            this->Print_number(false);

            if (this->is_negative)
            {
                std::cout << ")";
            }
        }
    }

    int Convert_to_10th()
    /* Функция. Возвращает десятичное представление восьмеричного числа, если это возможно.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   int result : десятичное число, результат перевода текущего числа.
     */
    {
        // Переменная, хранящая результат перевода.
        int result{0};

        // Переменная для хранения текущей разрядности.
        int digit{1};

        // Указатель на крайнюю правую цифру текущего числа.
        int first{this->max_length - 1};

        // Если текущее число является нулем, вернуть нуль.
        if (this->container[0] == '.')
        {
            return result;
        }

        // Поиск крайней правой цифры в текущем числе.
        while (this->container[first] == '.')
        {
            first--;
        }

        // Пробегаем по всем цифрам в текущем числе.
        for (int i = first; i >= 0; i--)
        {
            // Текущий разряд устанавливается равным единицам.
            digit = 1;

            // Увеличение текущего разряда до 10 ^ i.
            for (int j = first - i; j > 0; j--)
            {
                // Если при умножении не произойдет переполнение, выполнить умножение.
                if (digit <= INT_MAX / BASE)
                {
                    digit *= BASE;
                }

                    // Иначе вывести ошибку при переводе.
                else
                {
                    std::cout << "Произошло переполнение при переводе. Операция не выполнена.";
                    return 0;
                }
            }

            // Увеличение result на digit this->container[first] раз.
            for (int j = this->container[first] - '0'; j > 0; j--)
            {
                // Если при сложении не произойдет переполнение, выполнить сложение.
                if (result < INT_MAX - digit)
                {
                    result += digit;
                }
                    // Иначе вывести ошибку при переводе.
                else
                {
                    std::cout << "Произошло переполнение при переводе. Операция не выполнена.";
                    return 0;
                }
            }
        }

        // Сделать result отрицательным, если текущее число является отрицательным.
        if ((this->is_negative))
        {
            result *= -1;
        }

        return result;
    }

    double cosh()
    /* Функция. Возвращает значение гиперболического косинуса для текущего числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   double : результат вычисления cosh для текущего числа в десятичной системе.
     */
    {
        return ::cosh(this->Convert_to_10th());
    }

    int cosh(bool mention)
    /* Функция. Собственная реализация гиперболического косинуса для восьмеричного числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   int : возвращает приближенное значение функции cosh для текущего числа.
     */
    {
        double result{1}, fact, temp, x;

        x = this->Convert_to_10th();
        for (int i = 1; i < 4; i++)
        {
            fact = factorial(2 * i);
            if (fact == -1)
            {
                std::cout << "Функции не понравился слишком большой вывод." << std::endl;
                return 0;
            }
            temp = pow(x, 2 * i) / factorial(2 * i);

            if (floor(result) < INT_MAX - temp)
            {
                result += temp;
            }
            else
            {
                std::cout << "Функции не понравился слишком большой вывод." << std::endl;
                return 0;
            }
        }

        if (mention)
        {
            std::cout << "Прямо сейчас вы наблюдаете результат работы перегруженной функции. Наслаждайтесь." << std::endl;
        }

        return floor(result);
    }

    Oct_number abs()
    /* Функция. Возвращает модуль числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Oct_number new_object : положительное восьмеричное число, созданное на базе текущего объекта.
     */
    {
        Oct_number new_object{*this};
        new_object.is_negative = false;

        return new_object;
    }

    Oct_number &operator=(const Oct_number &object)
    /* Оператор присваивания.
     * Копирует значения атрибутов объекта object в атрибуты текущего объекта и возвращает текущий объект.
     * Параметры:
     *   const Oct_number &object : объект, атрибуты которого копируются в текущий объект.
     * Возвращаемое значение:
     *   Oct_number *this : текузий объект, которому были присвоены значения атрибутов object.
     */
    {
        // Выполнять переприсваивание только в том случае, если два объекта
        // не ссылаются на одно и то же место в памяти (не являются одним и тем же).
        if (&object != this)
        {
            // Копирование всех чисел в массиве container объекта object
            // в соответствующий массив текущего объекта.
            for (int i = 0; i < this->max_length; i++)
            {
                this->container[i] = object.container[i];
                if (object.container[i] == '.')
                {
                    break;
                }
            }

            // Копирование знака объекта object в текущий объект.
            this->is_negative = object.is_negative;
        }
        return *this;
    }

    Oct_number operator+(Oct_number &object)
    /* Оператор сложения.
     * Возвращает сумму двух воьсмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Oct_number &object    : левый операнд операции сложения.
     * Возвращаемое значение:
     *   Oct_number new_object : число, хранящее сумму текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Oct_number new_object{false};

        // Переменная, хранящая в себе промежуточный результат вычисления суммы.
        Oct_number temp{false};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Текущая цифра в первом и во втором числе.
        char first_number, second_number;

        // Указатель, на какое место в массиве container объекта new_object ставить
        // очередную цифру.
        int digit{this->max_length - 1};

        // "Спасатель" - спасает от лишних точек в начале массива container объекта
        // new_object
        int rescuer{0};

        // Хранители новой цифры new_object и цифры, которая прибавляется к следующему разряду.
        // Пример: 5 + 7 = 12 -> cur=2, high=1.
        unsigned cur{0}, high{0};

        // Выполнять сложение без преобразования только в том случае, если знаки обоих чисел совпадают.
        if (this->is_negative == object.is_negative)
        {
            // Поиск позиции крайней парвой цифры объекта *this.
            while (this->container[first] == '.')
            {
                first--;
            }

            // Поиск позиции крайней правой цифры объекта object.
            while (object.container[second] == '.')
            {
                second--;
            }

            // Выполнять сложение до тех пор, пока хотя бы один из указателей на позицию имеет смысл
            // либо пока есть цифры, которые прибавляются к старшим разрядам.
            while (((first >= 0) || (second >= 0)) || (high > 0))
            {
                // Если в какой-то момент мы должны ставить число за пределы массива container,
                // фиксируем переполнение и возвращаем 0.
                if (digit < 0)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Если позиция first / second имеет смысл, то использовать значение по этой позиции, иначе считать нулем.
                first >= 0 ? first_number = this->container[first] : first_number = '.';
                second >= 0 ? second_number = object.container[second] : second_number = '.';

                // Если оба указателя (first, second) не имеют смысла...
                if ((first_number == '.') && (second_number) == '.')
                {
                    // ... то смотреть значение прибавляемой цифры.
                    // Если оно не равно нулю, то поставить соответствующее значение в new_object,
                    // иначе поставить '.'.
                    high == 0 ? new_object.container[digit] = '.' : new_object.container[digit] = '0' + high;

                    // Дальше цифр в числах уже не будет, сложение закончилось.
                    break;
                }

                    // Иначе если хотя бы один указатель не имеет смысла...
                else if ((first_number == '.') || (second_number) == '.')
                {
                    // Посмотреть, какой из указателей лишен смысла, и получить cur как сумма другого числа и
                    // цифры, передавшейся от младшего разряда.
                    first_number != '.' ? cur = first_number - '0' + high : cur = second_number - '0' + high;

                    // В старший разряд переходит все, что не поместилось в текущий.
                    high = cur / BASE;

                    // В текущем разряде остается все, что не поместилось в старший.
                    cur = cur % BASE;

                    // Текущий разряд записывается в объект new_object.
                    new_object.container[digit] = '0' + cur;
                }

                    // Иначе [все указатели имеют смысл]
                else
                {
                    // Получение текущей суммы цифр first_number и second_number с учетом прихода от младших разрядов.
                    cur = first_number + second_number + high - '0' - '0';

                    // В старший разряд переходит всеЮ что не поместилось в текущий.
                    high = cur / BASE;

                    // В текущем разряде остается все, что не поместилось в старший.
                    cur = cur % BASE;

                    // Текущий разряд записывается в объект new_object.
                    new_object.container[digit] = '0' + cur;
                }
                // Переход к следующим разрядам объектов *this, object и new_object.
                first--;
                second--;
                digit--;
            }

            // Поскольку знаки объектов *this и object совпадают, знак итогового выражения
            // может быть определен по знаку любого из операндов.
            new_object.is_negative = this->is_negative;

            // Поиск цифры старшего разряда для переноса числа из правой части массива container
            // в левую.
            while(new_object.container[rescuer] == '.')
            {
                rescuer++;
            }

            // Перенос чисел из правой части массива в левую.
            if (rescuer != 0)
            {
                for(int pos = 0; rescuer < this->max_length; pos++)
                {
                    new_object.container[pos] = new_object.container[rescuer];
                    new_object.container[rescuer] = '.';

                    rescuer++;
                }
            }
        }

            // Иначе выполнять сложение с преобразованием*.
            // *Преобразование - смена знака отрицательного числа на противоположную.
        else
        {
            // a + b = a - (-b), (-b) > 0;
            if (object.is_negative)
            {
                temp = -object;
                new_object = *this - temp;
            }

                // a + b = -((-a) - b), (-a) > 0;
            else
            {
                temp = -*this;
                new_object = -(temp - object);
            }
        }

        return new_object;
    }

    Oct_number operator-(Oct_number& object)
    /* Оператор вычитания.
     * Возвращает разность двух воьсмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Oct_number &object    : левый операнд операции вычитания.
     * Возвращаемое значение:
     *   Oct_number new_object : число, хранящее разность текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Oct_number new_object{false};

        // Переменные, хранящие промежуточные значения операций. Нужны для того,
        // чтобы объекты *this и object не изменялись в процессе выполнения кода.
        Oct_number temp{false}, this_copy{*this}, object_copy{object};

        // Переменные, хранящие наибольшее и наименьшее (по модулю) числа соответственно.
        Oct_number highest{false}, lowest{false};

        // Метка, показывающая, является ли значение объекта *this больше значения объекта object.
        bool this_is_higher{true};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Текущая цифра в первом и во втором числе.
        char first_number, second_number;

        // Указатель, на какое место в массиве container объекта new_object ставить
        // очередную цифру.
        int digit{this->max_length - 1};

        // "Спасатель" - спасает от лишних точек в начале массива container объекта new_object
        int rescuer{0};

        // Хранители новой цифры new_object и цифры, которая прибавляется к следующему разряду.
        // Пример: 5 + 7 = 12 -> cur=2, high=1.
        unsigned cur{0}, high{0};

        // Считать, что работаем с положительными числами, для корректной оценки величины чисел по модулю.
        this_copy.is_negative = false;
        object_copy.is_negative = false;

        this_is_higher = this_copy >= object_copy;

        // Присвоение объектам highest и lowest значений в зависимости от метки
        // this_is_higher.
        if (this_is_higher)
        {
            highest = *this;
            lowest = object;
        }
        else
        {
            highest = object;
            lowest = *this;
        }

        // Поиск поизции крайней парвой цифры объекта highest.
        while (highest.container[first] == '.')
        {
            first--;
        }

        // Поиск позиции крайней правой цифры объекта lowest.
        while (lowest.container[second] == '.')
        {
            second--;
        }

        // Выполнять вычитание без преобразования только в том случае, если знаки обоих чисел совпадают.
        if (highest.is_negative == lowest.is_negative)
        {
            // Выполнять вычитание до тех пор, пока не закончится первое (большее) число.
            while (first >= 0)
            {
                // Если в какой-то момент мы должны ставить число за пределы массива container,
                // фиксируем переполнение и возвращаем 0.
                if (digit < 0)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Если позиция second имеет смысл, то использовать значение по этой позиции, иначе считать нулем.
                first_number = highest.container[first];
                second >= 0 ? second_number = lowest.container[second] : second_number = '0';

                // Если first_number "не хватает", то заимствуем единичку из разряда выше.
                if (first_number - high < second_number)
                {
                    cur = BASE + (first_number - '0') - high - (second_number - '0');
                    high = 1;
                }

                    // Иначе спокойно вычитаем.
                else
                {
                    cur = (first_number - '0') - high - (second_number - '0');
                    high = 0;
                }

                // Текущий разряд записывается в объект new_object.
                new_object.container[digit] = '0' + cur;

                // Переход к следующим разрядам объектов highest, lowest и new_object.
                first--;
                second--;
                digit--;
            }

            // Поиск начала чисел указателем rescuer.
            while(new_object.container[rescuer] == '.')
            {
                rescuer++;
            }

            // Замена всех ведущих нулей на точки до первого ненулевого значения.
            // Если все цифры были нулевыми, то rescuer == this->max_length.
            while((new_object.container[rescuer] == '0') && (rescuer < this->max_length))
            {
                new_object.container[rescuer] = '.';
                rescuer++;
            }

            // Перенос значений с конца массива container объекта new_object в его начало.
            // Не выполняется, если число занимает весь массив либо число равно 0.
            if (rescuer != 0)
            {
                for(int pos = 0; rescuer < this->max_length; pos++)
                {
                    new_object.container[pos] = new_object.container[rescuer];
                    new_object.container[rescuer] = '.';

                    rescuer++;
                }
            }
        }

            // Иначе выполнять вычитание с преобразованием*.
            // *Преобразование - смена знака отрицательного числа на противоположную.
        else
        {
            // a - b = a + (-b), (-b) > 0
            if (lowest.is_negative)
            {
                temp = -lowest;
                new_object = highest + temp;
            }
                // a - b = -((-a) + b), (-a) > 0
            else
            {
                temp = -highest;
                new_object = -(temp + lowest);
            }
        }

        // Если наибольшее по модулю число является отрицательным, то результат будет отрицательным.
        // Вторая строка отвечает за перестановку: если большее число вычитается из меньшего,
        // то мы вычитаем из большего меньшее и инвертируем знак.
        new_object.is_negative = highest.is_negative;
        if (!(this_is_higher)) new_object.is_negative = !(new_object.is_negative);

        return new_object;
    }

    Oct_number operator*(Oct_number& object)
    /* Оператор умножения.
     * Возвращает произведение двух восьмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Oct_number &object    : левый операнд операции умножения.
     * Возвращаемое значение:
     *   Oct_number new_object : число, хранящее произведение текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Oct_number new_object{false};

        // Число для работы с модулем объекта *this.
        Oct_number this_copy{false};

        // Число, хранящее промежуточные результаты.
        Oct_number temp{false};

        this_copy = this->abs();

        // Инициализация:
        // > указателя на крайнюю левую цифру в массиве container;
        // > номера итерации, необходимого для уточнения разрядности;
        // > указателя на позицию, с которой следует начать заполнение нулями.
        int first{this->max_length - 1}, iteration{0}, pos;

        // Поиск положения крайней правой цифры в объекте object.
        while (object.container[first] == '.')
        {
            first--;
        }

        // Потворять операцию сложения до тех пор, пока в object не закончатся цифры.
        while (first >= 0)
        {
            // Обнулить указатель на место, откуда ставить нули, и временную переменную.
            pos = 0;
            temp.Set_zero();

            // Посчитать результат сложения текущего числа *this с самим собой counter раз.
            for (int counter = object.container[first] - '0'; counter > 0; counter--)
            {
                temp = this_copy + temp;
            }

            // Найти место в temp, откуда следует ставить нули (т. е. найти место, куда пишется "0" при умножении на 10).
            // Если pos дошел до конца массива и не нашел свободного места, зафиксировать переполнение.
            while ((temp.container[pos] != '.') && (pos < this->max_length))
            {
                pos++;
            }

            // Если в какой-то момент произошло переполнение, то вернуть 0.
            if (pos == this->max_length)
            {
                std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                new_object.Set_zero();
                return new_object;
            }

            for (unsigned digit = 0; digit < iteration; digit++)
            {
                // Если в какой-то момент произошло переполнение, то вернуть 0.
                if (pos + digit >= this->max_length)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Умножаем результат (*this) * counter на 10 iteration раз.
                // (За каждый шаг влево по object iteration возрастает на 1).
                temp.container[pos + digit] = '0';
            }

            // Увеличиваем текущий результат на temp.
            // Если произошло переполнение, возвращаем ноль.
            new_object = new_object + temp;
            if (new_object.container[this->max_length - 1] != '.')
            {
                std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                new_object.Set_zero();
                return new_object;
            }

            // Делаем шаг по разрядности +1, соответствующий указатель смещаем влево на одну позицию.
            iteration++;
            first--;
        }

        // Произведение двух чисел отрицательно тогда и только тогда, когда знаки чисел не совпадают.
        new_object.is_negative = !(this->is_negative == object.is_negative);

        return new_object;
    }

    Oct_number operator/(Oct_number& object)
    /* Оператор целочисленного деления.
     * Возвращает результат целочисленного деления восьмеричного числа *this на object в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Oct_number &object    : левый операнд операции целочисленного деления.
     * Возвращаемое значение:
     *   Oct_number new_object : число, хранящее результат целочисленного деления текущего объекта на объект object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Oct_number new_object{false};

        // Переменные, хранящие промежуточные значения операций. Нужны для того,
        // чтобы объекты *this и object не изменялись в процессе выполнения кода.
        Oct_number this_copy{*this}, object_copy{object};

        // Переменные. Нужны для корректной проверки равенства нулю делителя object
        // и корректного изменения результа в случае, если первое число является отрциательным.
        Oct_number zero{false}, one{false};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Инициализация:
        // > текущего результата деления;
        // > итерации для указания разрядности;
        // > указателя на положение вновь добавляемого (убираемого) нуля;
        int counter{0}, iteration{0}, cur_zero;

        // "Спасатель" - спасает от лишних точек в начале массива container объекта new_object
        int rescuer{0};

        // Метки для корректной обработки результата в случае, если первое число является отрицательным.
        bool first_is_negative, temp;

        // Инициализация числа one единицей.
        one.container[0] = '1';

        // Результат деления будет отрицательным, если оба опернда имеют различные знаки.
        // Инициализация метки first_is_negative соответствюущим атрибутом объекта this.
        new_object.is_negative = !(this->is_negative == object.is_negative);
        first_is_negative = this->is_negative;

        // Создаем копии объектов для того, чтобы оригинальные объекты не изменялись.
        // Для корректных операций вычитания делаем числа положительными.
        this_copy.is_negative = false;
        object_copy.is_negative = false;

        // Для экономии вычислений возвращаем нуль в случае, если правый операнд больше левого.
        if (this_copy < object_copy)
        {
            return new_object;
        }

        // Возвращаем нуль в случае, если правый операнд равен нулю.
        if (object_copy == zero)
        {
            std::cout << "Вы обнаружили пасхалку, поздравляю! Но на ноль делить нельзя." << std::endl;
            return new_object;
        }

        // Поиск позиции крайней правой цифры объекта this_copy.
        while (this_copy.container[first] == '.')
        {
            first--;
        }

        // Поиск позиции крайней правой цифры объекта object_copy.
        // Инициализация указателя, куда ставятся нули, позицией правой крайней цифры данного объекта.
        while (object_copy.container[second] == '.')
        {
            second--;
        }
        cur_zero = second;

        // До тех пор, пока количество цифр во втором числе не сравняется с количеством цифр в первом числе,
        // ставить в конец второго числа нули (умножать число object_copy на 10 до тех пор, пока оно по разрядности
        // не сравняется с числом this_copy).
        while (cur_zero < first)
        {
            cur_zero++;
            object_copy.container[cur_zero] = '0';
        }

        // До тех пор, пока в объекте object_copy сохраняются поставленные нами нули,
        // продолжать операцию деления.
        while (cur_zero >= second)
        {
            // Увеличение счетчика за каждую возможность вычесть из this_copy объект object_copy.
            counter = 0;
            while (this_copy >= object_copy)
            {
                this_copy = this_copy - object_copy;
                counter++;
            }

            // Полученное значение counter записывается на позицию iteration числа new_object.
            // При этом, если на позиции cur_zero объекта object_copy находится поставленный нами нуль, убираем его (делим число на 10).
            // Уменьшаем текущую позицию cur_zero на 1 и увеличиваем позицию iteration на 1.
            new_object.container[iteration] = '0' + counter;
            if (cur_zero != second)
            {
                object_copy.container[cur_zero] = '.';
            }

            // Переходим к следующему разряду числа new_object.
            cur_zero--;
            iteration++;
        }

        // Замена всех ведущих нулей на точки до первого ненулевого значения.
        // Если все цифры были нулевыми, то rescuer == this->max_length.
        while((new_object.container[rescuer] == '0') && (rescuer < this->max_length))
        {
            new_object.container[rescuer] = '.';
            rescuer++;
        }

        // Перенос значений с конца массива container объекта new_object в его начало.
        // Не выполняется, если число занимает весь массив либо число равно 0.
        if (rescuer != 0)
        {
            for(int pos = 0; rescuer < this->max_length; pos++)
            {
                new_object.container[pos] = new_object.container[rescuer];
                new_object.container[rescuer] = '.';

                rescuer++;
            }
        }


        /* Если результат является ненулевым и первое число является отрицательным,
         * то увеличить модуль результата на единицу.

         * Пояснение:
         * Если a / b = c (где sign(c) =  sign(a) * sign(b))
         * И    a > 0,
         * То   (-a) / b = -sign(c) * (|c| + 1)

         * Примеры:
         *  7 /  3 =  2; остаток 1
         *  7 / -3 = -2; остаток 1
         * -7 /  3 = -3; остаток 2
         * -7 / -3 =  3. остаток 2 */
        if ((this_copy.container[0] != '.') && (first_is_negative))
        {
            temp = new_object.is_negative;
            new_object = new_object.abs();
            new_object = new_object + one;
            new_object.is_negative = temp;
        }

        return new_object;
    }

    Oct_number operator%(Oct_number& object)
    /* Оператор получения остатка от целочисленного деления.
     * Возвращает остаток от целочисленного деления восьмеричного числа *this на object в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Oct_number &object    : левый операнд операции отстатка от целочисленного деления.
     * Возвращаемое значение:
     *   Oct_number new_object : число, хранящее результат отстатка от целочисленного деления текущего объекта на объект object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Oct_number new_object{false};

        // Пеерменная, необходимая для корректной проверки равенства нулю делителя object.
        Oct_number zero{false};

        // Возвращаем нуль в случае, если правый операнд равен нулю.
        if (object == zero)
        {
            std::cout << "Вы обнаружили пасхалку, поздравляю! Но на ноль делить нельзя." << std::endl;
            return new_object;
        }

        // Результат целочисленного деления *this / object.
        Oct_number multiplier{*this / object};

        // Если multiplier * object + new_object = *this, то new_object = *this - multiplier * object.

        // Промежуточная операция для вычисления второго слагаемого.
        multiplier = multiplier * object;

        // Вычисление результата.
        new_object = *this - multiplier;

        return new_object;
    }

    Oct_number operator+()
    /* Унарный плюс.
     * Возвращает восьмеричное число, созданное на базе текущего объекта, с сохранением знака.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Oct_number new_object : число, аналогичное текущему объекту, с сохраненным знаком.
     */
    {
        Oct_number new_object{*this};
        new_object.is_negative = this->is_negative;
        return new_object;
    }

    Oct_number operator-()
    /* Унарный минус.
     * Возвращает восьмеричное число, созданное на базе текущего объекта, с инверсией знака.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Oct_number new_object : число, аналогичное текущему объекту, с инверсированным знаком.
     */
    {
        Oct_number new_object{*this};
        new_object.is_negative = !(this->is_negative);
        return new_object;
    }

    bool operator >(Oct_number& object)
    /* Оператор сравнения "больше".
     * Возвращает true, если левый операнд хранит число, большее, чем число, хранящееся в правом операнде, и false в противном случае.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool this_is_higher         : результат сравнения.
     */
    {
        // Инициализация:
        // > метки, указывающей, является ли число *this наибольшим;
        // > метки, указывающей, нужно ли пропускать операции сравнения двух цифр;
        // > метки, указывающей, нужно ли инвертировать результат сравнения (true, если оба числа отрицательны).
        bool this_is_higher{true}, skip{false}, reverse{false};

        // Если первое число положительно, а второе - отрицательно, вернуть true.
        if ((this->is_negative == false) && (object.is_negative == true))
        {
            return true;
        }
            // Иначе, если первое число отрицательно, а второе - положительно, вернуть false.
        else if ((this->is_negative == true) && (object.is_negative == false))
        {
            return false;
        }
            // Иначе, если оба числа отрицательны, инвертировать резельтат сравнения по модулю.
        else if ((this->is_negative == true) && (object.is_negative == true))
        {
            reverse = true;
        }
        // Иначе [оба числа положительны, инвретировать ничего не нужно, случай учтен при инициализации]

        // Пробегаемся по всем элементам массивов container обоих чисел.
        for (int pos = 0; pos < this->max_length; pos++)
        {
            // Если оба элементы являются точками, сравнение закончено (т. к. результат известен).
            if ((this->container[pos] == '.') && (object.container[pos] == '.'))
            {
                break;
            }
                // Иначе если второе число закончилось раньше, сравнение закончено (первое число больше).
            else if ((this->container[pos] != '.') && (object.container[pos] == '.'))
            {
                this_is_higher = true;
                break;
            }
                // Иначе если первое число закончено раньше, сравнение закончено (второе число больше).
            else if ((this->container[pos] == '.') && (object.container[pos] != '.'))
            {
                this_is_higher = false;
                break;
            }
                // Иначе у обоих чисел на данной позции имеются цифры, и...

                // ..если цифра первого числа больше цифры второго, то при равной разрядности первое число будет больше.
                // Остальные цифры можно не сравнивать - нужно проверить только разрядность чисел.
            else if ((this->container[pos] > object.container[pos]) && !(skip))
            {
                this_is_higher = true;
                skip = true;
                continue;
            }
                // ...если цифра первого числа равна цифре второго, то ничего сказать нельзя.
                // Если до этого все остальные цифры также были равны, то считается, что (*this == object) = true.
            else if ((this->container[pos] == object.container[pos]) && !(skip))
            {
                this_is_higher = false;
                continue;
            }

                // ...если мы не пропускаем проверку, то цифра первого числа меньше цифры второго и при равной
                // разрядности второе число будет больше.
                // Остальные цифры можно не сравнивать - нужно проверить только разрядность чисел.
            else if (!(skip))
            {
                this_is_higher = false;
                skip = true;
            }

        }

        // Если оба числа отрицательны, то меняем результат сравнения на протиположный.
        if (reverse)
        {
            this_is_higher = !this_is_higher;
        }

        return this_is_higher;
    }

    bool operator ==(Oct_number& object)
    /* Оператор сравнения "равно".
     * Возвращает true, если числа, хранящиеся в обоих операндах, равны, и false в противном случае.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения.
     */
    {
        // Объявление возвращаемой метки.
        bool result{false};

        // Если знаки чисел не совпадают, то сразу вернуть false.
        if (this->is_negative != object.is_negative)
        {
            return result;
        }

        // Сравнение соответствующих символов в массивах container обоих чисел.
        for (int i = 0; i < max_length - 1; i++)
        {
            // Если находится хотя бы одно отличие, возвращается false.
            if (this->container[i] != object.container[i])
            {
                return result;
            }
        }

        // Если знаки чисел равны, а их массивы container содержат одинаковые знаки,
        // возвращается true.
        result = true;
        return result;
    }

    bool operator !=(Oct_number& object)
    /* Оператор сравнения "не равно".
     * Возвращает true, если числа, хранящиеся в обоих операндах, не равны, и false в противном случае.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return !(*this == object);
    }

    bool operator >=(Oct_number& object)
    /* Оператор сравнения "больше либо равно".
     * Возвращает true, если число, хранящееся в левом операнде, больше либо равно числу,
     * хранящемуся в правом операнде.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return ((*this > object) || (*this == object));
    }

    bool operator <(Oct_number& object)
    /* Оператор сравнения "меньше".
     * Возвращает true, если число, хранящееся в левом операнде, меньше числа, хранящегося в правом операнде.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return (!(*this >= object));
    }

    bool operator <=(Oct_number& object)
    /* Оператор сравнения "меньше либо равно".
     * Возвращает true, если число, хранящееся в левом операнде, меньше либо равно числу,
     * хранящемуся в правом операнде.
     * Параметры:
     *   Oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return (!(*this > object));
    }

    ~Oct_number()
    /* Деструктор. Удаляет данные динамического массива container.
     */
    {
        delete[] this->container;
        // std::cout << "Удаление восьмеричного числа.\n";
    }
};

class Extended_oct_number : public Oct_number
/* Класс "расширенное восьмеричное число". Наследник класса "восьмеричное число".
 * Может хранить числа до 100 цифр, а также представляет функционал арифметических
 * операций и операций сравнения.
 */
{
public:

    Extended_oct_number(bool state) : Oct_number(false)
    /* Конструктор. Создает число типа Extended_oct_number
     * Параметры:
     *   bool state : указывает, нужно ли иницализировать число вводом с клавиатуры.
     */
    {
        // Метка. Показывает, является ли введеное число корректным.
        bool not_okay{true};

        // Метки. Показывают, является ли очередной символ числом / минусом.
        bool c_is_number{false}, c_is_minus{false};

        // Вспомогательная переменная. Используется для заполнения массива container.
        unsigned j;

        // Вспомогательная переменная. Хранит в себе значение очередного ввода пользователя.
        std::string answer;

        // Переопределение максимальной длины числа на 100.
        this->max_length = 100;

        // Удаление предыдущего динамического массива container длиной max_length в классе Oct_number.
        // Инциализация container массивом длиной max_length.
        // По умолчанию все создаваемые числа положительны.
        delete[] this->container;
        this->container = new char[this->max_length];
        this->is_negative = false;

        // По умолчанию число равно нулю.
        for (int i = 0; i < this->max_length; i++)
        {
            this->container[i] = '.';
        }

        // Код ниже выполняется только в том случае, если для числа требуется явная инициализация
        // (когда пользователя просят явно ввести число).
        if (state)
        {
            // Ввод числа будет продолжаться до тех пор, пока не будет введено корректное восьмеричное число.
            while (not_okay)
            {
                // Начать заполнять массив container заново.
                j = 0;

                // Считать, что по началу число является правильным (до встречи с ошибкой).
                not_okay = false;

                std::cout << "Введите восьмеричное число: ";
                std::cin >> answer;

                // Сброс заполнения, если длина введенной строки превышает максимальную.
                if (answer.length() > this->max_length)
                {
                    std::cout << "Длина числа превышает максимальную. Число не было считано." << std::endl;
                    this->is_negative = false;
                    not_okay = true;
                    continue;
                }

                    // Если введеная строка представляет собой единственный ноль, то ничего не делать (выйти из цикла).
                    // (По умолчанию число инциализировано нулем).
                else if ((answer[0] == '0') && (answer.length() == 1))
                {
                    break;
                }

                else
                {
                    // Если не выполнились два предыдущих условия, то идет посимвольная проверка и запись
                    // строки answer в массив container.
                    for (auto c : answer)
                    {
                        // Является ли символ c допустимым для восьмеричной системы счисления числом?
                        c_is_number = ('0' <= c) && (c <= '0' + BASE - 1);

                        // Является ли символ с начальным минусом?
                        c_is_minus = (j == 0) && (c == '-');

                        // Если символ c не является допустимым числом или начальным минусом ИЛИ если символ c является
                        // нулем в начале всего числа, происходит сброс заполнения.
                        if (!(c_is_number || c_is_minus) || ((c == '0') && (j == 0)))
                        {
                            std::cout << "Введены некорректные символы. Число не было считано." << std::endl;
                            for (int i = 0; i < max_length; i++)
                            {
                                this->container[i] = '.';
                            }
                            this->is_negative = false;
                            not_okay = true;
                            break;
                        }
                        // Если символ c является начальным минусом, то объявить число отрицательным,
                        // не смещая порядок записи в массив container.
                        if (c_is_minus)
                        {
                            this->is_negative = true;
                        }

                            // В противном случае записать символ c в массив container и сдвинуть
                            // указатель j на следующую позицию.
                        else
                        {
                            this->container[j] = c;
                            j++;
                        }
                    }
                }
            }
        }
    }

    Extended_oct_number(const Extended_oct_number& object) : Oct_number(false)
    /* Конструктор копирования. Создает число типа Extended_oct_number на основе другого числа типа Extended_oct_number.
     * Параметры:
     *   const Extended_oct_number& object : число, на базе которого создается новое число.
     */
    {
        // Переопределение максимальной длины числа на 100.
        this->max_length = 100;

        // Удаление предыдущего динамического массива container длиной 10.
        // Инциализация container массивом длиной max_length.
        delete[] this->container;
        this->container = new char[this->max_length];

        // Копирование всех знаков из массива container объекта object в
        // массив container текущего объекта.
        for (int i = 0; i < this->max_length; i++)
        {
            this->container[i] = object.container[i];
        }

        // Копирование атрибута is_negative объекта object
        // в атрибут is_negative текущего объекта.
        this->is_negative = object.is_negative;
    }

    void Change_number()
    /* Функция. Изменяет значение, хранящееся в массиве container текущего объекта.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Нет
     */
    {
        // Метка. Показывает, является ли введеное число корректным.
        bool not_okay{true};

        // Метки. Показывают, является ли очередной символ числом / минусом.
        bool c_is_number{false}, c_is_minus{false};

        // Вспомогательная переменная. Используется для заполнения массива container.
        unsigned j;

        // Вспомогательная переменная. Хранит в себе значение очередного ввода пользователя.
        std::string answer;

        // Освобождение памяти от предыдущего значения числа.
        // Инциализация container массивом длиной max_length.
        // По умолчанию все создаваемые числа положительны.
        delete[] this->container;
        this->container = new char[this->max_length];
        this->is_negative = false;

        // По умолчанию число равно нулю.
        for (int i = 0; i < this->max_length; i++)
        {
            this->container[i] = '.';
        }

        // Ввод числа будет продолжаться до тех пор, пока не будет введено корректное восьмеричное число.
        while (not_okay)
        {
            // Начать заполнять массив container заново.
            j = 0;

            // Считать, что по началу число является правильным (до встречи с ошибкой).
            not_okay = false;

            std::cout << "Введите восьмеричное число: ";
            std::cin >> answer;

            // Сброс заполнения, если длина введенной строки превышает максимальную.
            if (answer.length() > this->max_length)
            {
                std::cout << "Длина числа превышает максимальную. Число не было считано." << std::endl;
                this->is_negative = false;
                not_okay = true;
                continue;
            }

                // Если введеная строка представляет собой единственный ноль, то ничего не делать (выйти из цикла).
                // (По умолчанию число инциализировано нулем).
            else if ((answer[0] == '0') && (answer.length() == 1))
            {
                break;
            }

            else
            {
                // Если не выполнились два предыдущих условия, то идет посимвольная проверка и запись
                // строки answer в массив container.
                for (auto c : answer)
                {
                    // Является ли символ c допустимым для восьмеричной системы счисления числом?
                    c_is_number = ('0' <= c) && (c <= '0' + BASE - 1);

                    // Является ли символ с начальным минусом?
                    c_is_minus = (j == 0) && (c == '-');

                    // Если символ c не является допустимым числом или начальным минусом ИЛИ если символ c является
                    // нулем в начале всего числа, происходит сброс заполнения.
                    if (!(c_is_number || c_is_minus) || ((c == '0') && (j == 0)))
                    {
                        std::cout << "Введены некорректные символы. Число не было считано." << std::endl;
                        for (int i = 0; i < max_length; i++)
                        {
                            this->container[i] = '.';
                        }
                        this->is_negative = false;
                        not_okay = true;
                        break;
                    }
                    // Если символ c является начальным минусом, то объявить число отрицательным,
                    // не смещая порядок записи в массив container.
                    if (c_is_minus)
                    {
                        this->is_negative = true;
                    }

                        // В противном случае записать символ c в массив container и сдвинуть
                        // указатель j на следующую позицию.
                    else
                    {
                        this->container[j] = c;
                        j++;
                    }
                }
            }
        }
    }

    int Convert_to_10th()
    /* Функция. Возвращает десятичное представление восьмеричного числа, если это возможно.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   int result : десятичное число, результат перевода текущего числа.
     */
    {
        // Переменная, хранящая результат перевода.
        int result{0};

        // Переменная для хранения текущей разрядности.
        int digit{1};

        // Указатель на крайнюю правую цифру текущего числа.
        int first{this->max_length - 1};

        // Если текущее число является нулем, вернуть нуль.
        if (this->container[0] == '.')
        {
            return result;
        }

        // Поиск крайней правой цифры в текущем числе.
        while (this->container[first] == '.')
        {
            first--;
        }

        // Пробегаем по всем цифрам в текущем числе.
        for (int i = first; i >= 0; i--)
        {
            // Текущий разряд устанавливается равным единицам.
            digit = 1;

            // Увеличение текущего разряда до 10 ^ i.
            for (int j = first - i; j > 0; j--)
            {
                // Если при умножении не произойдет переполнение, выполнить умножение.
                if (digit <= INT_MAX / BASE)
                {
                    digit *= BASE;
                }

                    // Иначе вывести ошибку при переводе.
                else
                {
                    std::cout << "Произошло переполнение при переводе. Операция не выполнена.";
                    return 0;
                }
            }

            // Увеличение result на digit this->container[first] раз.
            for (int j = this->container[first] - '0'; j > 0; j--)
            {
                // Если при сложении не произойдет переполнение, выполнить сложение.
                if (result < INT_MAX - digit)
                {
                    result += digit;
                }
                    // Иначе вывести ошибку при переводе.
                else
                {
                    std::cout << "Произошло переполнение при переводе. Операция не выполнена.";
                    return 0;
                }
            }
        }

        // Сделать result отрицательным, если текущее число является отрицательным.
        if ((this->is_negative))
        {
            result *= -1;
        }

        return result;
    }

    double cosh()
    /* Функция. Возвращает значение гиперболического косинуса для текущего числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   double : результат вычисления cosh для текущего числа в десятичной системе.
     */
    {
        return ::cosh(this->Convert_to_10th());
    }

    int cosh(bool mention)
    /* Функция. Собственная реализация гиперболического косинуса для восьмеричного числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   int : возвращает приближенное значение функции cosh для текущего числа.
     */
    {
        double result{1}, fact, temp, x;

        x = this->Convert_to_10th();
        for (int i = 1; i < 4; i++)
        {
            fact = factorial(2 * i);
            if (fact == -1)
            {
                std::cout << "Функции не понравился слишком большой вывод." << std::endl;
                return 0;
            }
            temp = pow(x, 2 * i) / factorial(2 * i);

            if (floor(result) < INT_MAX - temp)
            {
                result += temp;
            }
            else
            {
                std::cout << "Функции не понравился слишком большой вывод." << std::endl;
                return 0;
            }
        }

        if (mention)
        {
            std::cout << "Прямо сейчас вы наблюдаете результат работы перегруженной функции. Наслаждайтесь." << std::endl;
        }

        return floor(result);
    }

    Extended_oct_number abs()
    /* Функция. Возвращает модуль числа.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Extended_oct_number new_object : положительное восьмеричное число, созданное на базе текущего объекта.
     */
    {
        Extended_oct_number new_object{*this};
        new_object.is_negative = false;

        return new_object;
    }

    Extended_oct_number &operator=(const Extended_oct_number &object)
    /* Оператор присваивания.
     * Копирует значения атрибутов объекта object в атрибуты текущего объекта и возвращает текущий объект.
     * Параметры:
     *   const Extended_oct_number &object : объект, атрибуты которого копируются в текущий объект.
     * Возвращаемое значение:
     *   Extended_oct_number *this : текузий объект, которому были присвоены значения атрибутов object.
     */
    {
        // Выполнять переприсваивание только в том случае, если два объекта
        // не ссылаются на одно и то же место в памяти (не являются одним и тем же).
        if (&object != this)
        {
            // Копирование всех чисел в массиве container объекта object
            // в соответствующий массив текущего объекта.
            for (int i = 0; i < this->max_length; i++)
            {
                this->container[i] = object.container[i];
                if (object.container[i] == '.')
                {
                    break;
                }
            }

            // Копирование знака объекта object в текущий объект.
            this->is_negative = object.is_negative;
        }
        return *this;
    }

    Extended_oct_number operator+(Extended_oct_number &object)
    /* Оператор сложения.
     * Возвращает сумму двух воьсмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Extended_oct_number &object    : левый операнд операции сложения.
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, хранящее сумму текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Extended_oct_number new_object{false};

        // Переменная, хранящая в себе промежуточный результат вычисления суммы.
        Extended_oct_number temp{false};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Текущая цифра в первом и во втором числе.
        char first_number, second_number;

        // Указатель, на какое место в массиве container объекта new_object ставить
        // очередную цифру.
        int digit{this->max_length - 1};

        // "Спасатель" - спасает от лишних точек в начале массива container объекта
        // new_object
        int rescuer{0};

        // Хранители новой цифры new_object и цифры, которая прибавляется к следующему разряду.
        // Пример: 5 + 7 = 12 -> cur=2, high=1.
        unsigned cur{0}, high{0};

        // Выполнять сложение без преобразования только в том случае, если знаки обоих чисел совпадают.
        if (this->is_negative == object.is_negative)
        {
            // Поиск позиции крайней парвой цифры объекта *this.
            while (this->container[first] == '.')
            {
                first--;
            }

            // Поиск позиции крайней правой цифры объекта object.
            while (object.container[second] == '.')
            {
                second--;
            }

            // Выполнять сложение до тех пор, пока хотя бы один из указателей на позицию имеет смысл
            // либо пока есть цифры, которые прибавляются к старшим разрядам.
            while (((first >= 0) || (second >= 0)) || (high > 0))
            {
                // Если в какой-то момент мы должны ставить число за пределы массива container,
                // фиксируем переполнение и возвращаем 0.
                if (digit < 0)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Если позиция first / second имеет смысл, то использовать значение по этой позиции, иначе считать нулем.
                first >= 0 ? first_number = this->container[first] : first_number = '.';
                second >= 0 ? second_number = object.container[second] : second_number = '.';

                // Если оба указателя (first, second) не имеют смысла...
                if ((first_number == '.') && (second_number) == '.')
                {
                    // ... то смотреть значение прибавляемой цифры.
                    // Если оно не равно нулю, то поставить соответствующее значение в new_object,
                    // иначе поставить '.'.
                    high == 0 ? new_object.container[digit] = '.' : new_object.container[digit] = '0' + high;

                    // Дальше цифр в числах уже не будет, сложение закончилось.
                    break;
                }

                    // Иначе если хотя бы один указатель не имеет смысла...
                else if ((first_number == '.') || (second_number) == '.')
                {
                    // Посмотреть, какой из указателей лишен смысла, и получить cur как сумма другого числа и
                    // цифры, передавшейся от младшего разряда.
                    first_number != '.' ? cur = first_number - '0' + high : cur = second_number - '0' + high;

                    // В старший разряд переходит все, что не поместилось в текущий.
                    high = cur / BASE;

                    // В текущем разряде остается все, что не поместилось в старший.
                    cur = cur % BASE;

                    // Текущий разряд записывается в объект new_object.
                    new_object.container[digit] = '0' + cur;
                }

                    // Иначе [все указатели имеют смысл]
                else
                {
                    // Получение текущей суммы цифр first_number и second_number с учетом прихода от младших разрядов.
                    cur = first_number + second_number + high - '0' - '0';

                    // В старший разряд переходит всеЮ что не поместилось в текущий.
                    high = cur / BASE;

                    // В текущем разряде остается все, что не поместилось в старший.
                    cur = cur % BASE;

                    // Текущий разряд записывается в объект new_object.
                    new_object.container[digit] = '0' + cur;
                }
                // Переход к следующим разрядам объектов *this, object и new_object.
                first--;
                second--;
                digit--;
            }

            // Поскольку знаки объектов *this и object совпадают, знак итогового выражения
            // может быть определен по знаку любого из операндов.
            new_object.is_negative = this->is_negative;

            // Поиск цифры старшего разряда для переноса числа из правой части массива container
            // в левую.
            while(new_object.container[rescuer] == '.')
            {
                rescuer++;
            }

            // Перенос чисел из правой части массива в левую.
            if (rescuer != 0)
            {
                for(int pos = 0; rescuer < this->max_length; pos++)
                {
                    new_object.container[pos] = new_object.container[rescuer];
                    new_object.container[rescuer] = '.';

                    rescuer++;
                }
            }
        }

            // Иначе выполнять сложение с преобразованием*.
            // *Преобразование - смена знака отрицательного числа на противоположную.
        else
        {
            // a + b = a - (-b), (-b) > 0;
            if (object.is_negative)
            {
                temp = -object;
                new_object = *this - temp;
            }

                // a + b = -((-a) - b), (-a) > 0;
            else
            {
                temp = -*this;
                new_object = -(temp - object);
            }
        }

        return new_object;
    }

    Extended_oct_number operator-(Extended_oct_number& object)
    /* Оператор вычитания.
     * Возвращает разность двух воьсмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Extended_oct_number &object    : левый операнд операции вычитания.
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, хранящее разность текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Extended_oct_number new_object{false};

        // Переменные, хранящие промежуточные значения операций. Нужны для того,
        // чтобы объекты *this и object не изменялись в процессе выполнения кода.
        Extended_oct_number temp{false}, this_copy{*this}, object_copy{object};

        // Переменные, хранящие наибольшее и наименьшее (по модулю) числа соответственно.
        Extended_oct_number highest{false}, lowest{false};

        // Метка, показывающая, является ли значение объекта *this больше значения объекта object.
        bool this_is_higher{true};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Текущая цифра в первом и во втором числе.
        char first_number, second_number;

        // Указатель, на какое место в массиве container объекта new_object ставить
        // очередную цифру.
        int digit{this->max_length - 1};

        // "Спасатель" - спасает от лишних точек в начале массива container объекта new_object
        int rescuer{0};

        // Хранители новой цифры new_object и цифры, которая прибавляется к следующему разряду.
        // Пример: 5 + 7 = 12 -> cur=2, high=1.
        unsigned cur{0}, high{0};

        // Считать, что работаем с положительными числами, для корректной оценки величины чисел по модулю.
        this_copy.is_negative = false;
        object_copy.is_negative = false;

        this_is_higher = this_copy >= object_copy;

        // Присвоение объектам highest и lowest значений в зависимости от метки
        // this_is_higher.
        if (this_is_higher)
        {
            highest = *this;
            lowest = object;
        }
        else
        {
            highest = object;
            lowest = *this;
        }

        // Поиск поизции крайней парвой цифры объекта highest.
        while (highest.container[first] == '.')
        {
            first--;
        }

        // Поиск позиции крайней правой цифры объекта lowest.
        while (lowest.container[second] == '.')
        {
            second--;
        }

        // Выполнять вычитание без преобразования только в том случае, если знаки обоих чисел совпадают.
        if (highest.is_negative == lowest.is_negative)
        {
            // Выполнять вычитание до тех пор, пока не закончится первое (большее) число.
            while (first >= 0)
            {
                // Если в какой-то момент мы должны ставить число за пределы массива container,
                // фиксируем переполнение и возвращаем 0.
                if (digit < 0)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Если позиция second имеет смысл, то использовать значение по этой позиции, иначе считать нулем.
                first_number = highest.container[first];
                second >= 0 ? second_number = lowest.container[second] : second_number = '0';

                // Если first_number "не хватает", то заимствуем единичку из разряда выше.
                if (first_number - high < second_number)
                {
                    cur = BASE + (first_number - '0') - high - (second_number - '0');
                    high = 1;
                }

                    // Иначе спокойно вычитаем.
                else
                {
                    cur = (first_number - '0') - high - (second_number - '0');
                    high = 0;
                }

                // Текущий разряд записывается в объект new_object.
                new_object.container[digit] = '0' + cur;

                // Переход к следующим разрядам объектов highest, lowest и new_object.
                first--;
                second--;
                digit--;
            }

            // Поиск начала чисел указателем rescuer.
            while(new_object.container[rescuer] == '.')
            {
                rescuer++;
            }

            // Замена всех ведущих нулей на точки до первого ненулевого значения.
            // Если все цифры были нулевыми, то rescuer == this->max_length.
            while((new_object.container[rescuer] == '0') && (rescuer < this->max_length))
            {
                new_object.container[rescuer] = '.';
                rescuer++;
            }

            // Перенос значений с конца массива container объекта new_object в его начало.
            // Не выполняется, если число занимает весь массив либо число равно 0.
            if (rescuer != 0)
            {
                for(int pos = 0; rescuer < this->max_length; pos++)
                {
                    new_object.container[pos] = new_object.container[rescuer];
                    new_object.container[rescuer] = '.';

                    rescuer++;
                }
            }
        }

            // Иначе выполнять вычитание с преобразованием*.
            // *Преобразование - смена знака отрицательного числа на противоположную.
        else
        {
            // a - b = a + (-b), (-b) > 0
            if (lowest.is_negative)
            {
                temp = -lowest;
                new_object = highest + temp;
            }
                // a - b = -((-a) + b), (-a) > 0
            else
            {
                temp = -highest;
                new_object = -(temp + lowest);
            }
        }

        // Если наибольшее по модулю число является отрицательным, то результат будет отрицательным.
        // Вторая строка отвечает за перестановку: если большее число вычитается из меньшего,
        // то мы вычитаем из большего меньшее и инвертируем знак.
        new_object.is_negative = highest.is_negative;
        if (!(this_is_higher)) new_object.is_negative = !(new_object.is_negative);

        return new_object;
    }

    Extended_oct_number operator*(Extended_oct_number& object)
    /* Оператор умножения.
     * Возвращает произведение двух восьмеричных чисел в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Extended_oct_number &object    : левый операнд операции умножения.
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, хранящее произведение текущего объекта и объекта object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Extended_oct_number new_object{false};

        // Число для работы с модулем объекта *this.
        Extended_oct_number this_copy{false};

        // Число, хранящее промежуточные результаты.
        Extended_oct_number temp{false};

        this_copy = this->abs();

        // Инициализация:
        // > указателя на крайнюю левую цифру в массиве container;
        // > номера итерации, необходимого для уточнения разрядности;
        // > указателя на позицию, с которой следует начать заполнение нулями.
        int first{this->max_length - 1}, iteration{0}, pos;

        // Поиск положения крайней правой цифры в объекте object.
        while (object.container[first] == '.')
        {
            first--;
        }

        // Потворять операцию сложения до тех пор, пока в object не закончатся цифры.
        while (first >= 0)
        {
            // Обнулить указатель на место, откуда ставить нули, и временную переменную.
            pos = 0;
            temp.Set_zero();

            // Посчитать результат сложения текущего числа *this с самим собой counter раз.
            for (int counter = object.container[first] - '0'; counter > 0; counter--)
            {
                temp = this_copy + temp;
            }

            // Найти место в temp, откуда следует ставить нули (т. е. найти место, куда пишется "0" при умножении на 10).
            // Если pos дошел до конца массива и не нашел свободного места, зафиксировать переполнение.
            while ((temp.container[pos] != '.') && (pos < this->max_length))
            {
                pos++;
            }

            // Если в какой-то момент произошло переполнение, то вернуть 0.
            if (pos == this->max_length)
            {
                std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                new_object.Set_zero();
                return new_object;
            }

            for (unsigned digit = 0; digit < iteration; digit++)
            {
                // Если в какой-то момент произошло переполнение, то вернуть 0.
                if (pos + digit >= this->max_length)
                {
                    std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                    new_object.Set_zero();
                    return new_object;
                }

                // Умножаем результат (*this) * counter на 10 iteration раз.
                // (За каждый шаг влево по object iteration возрастает на 1).
                temp.container[pos + digit] = '0';
            }

            // Увеличиваем текущий результат на temp.
            // Если произошло переполнение, возвращаем ноль.
            new_object = new_object + temp;
            if (new_object.container[this->max_length - 1] != '.')
            {
                std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
                new_object.Set_zero();
                return new_object;
            }

            // Делаем шаг по разрядности +1, соответствующий указатель смещаем влево на одну позицию.
            iteration++;
            first--;
        }

        // Произведение двух чисел отрицательно тогда и только тогда, когда знаки чисел не совпадают.
        new_object.is_negative = !(this->is_negative == object.is_negative);

        return new_object;
    }

    Extended_oct_number operator/(Extended_oct_number& object)
    /* Оператор целочисленного деления.
     * Возвращает результат целочисленного деления восьмеричного числа *this на object в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Extended_oct_number &object    : левый операнд операции целочисленного деления.
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, хранящее результат целочисленного деления текущего объекта на объект object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Extended_oct_number new_object{false};

        // Переменные, хранящие промежуточные значения операций. Нужны для того,
        // чтобы объекты *this и object не изменялись в процессе выполнения кода.
        Extended_oct_number this_copy{*this}, object_copy{object};

        // Переменные. Нужны для корректной проверки равенства нулю делителя object
        // и корректного изменения результа в случае, если первое число является отрциательным.
        Extended_oct_number zero{false}, one{false};

        // Указатели, которые будут указывать на правую крайнюю позицию числа в массивах
        // container текущего объекта и объекта object.
        int first{this->max_length - 1}, second{this->max_length - 1};

        // Инициализация:
        // > текущего результата деления;
        // > итерации для указания разрядности;
        // > указателя на положение вновь добавляемого (убираемого) нуля;
        int counter{0}, iteration{0}, cur_zero;

        // "Спасатель" - спасает от лишних точек в начале массива container объекта new_object
        int rescuer{0};

        // Метки для корректной обработки результата в случае, если первое число является отрицательным.
        bool first_is_negative, temp;

        // Инициализация числа one единицей.
        one.container[0] = '1';

        // Результат деления будет отрицательным, если оба опернда имеют различные знаки.
        // Инициализация метки first_is_negative соответствюущим атрибутом объекта this.
        new_object.is_negative = !(this->is_negative == object.is_negative);
        first_is_negative = this->is_negative;

        // Создаем копии объектов для того, чтобы оригинальные объекты не изменялись.
        // Для корректных операций вычитания делаем числа положительными.
        this_copy.is_negative = false;
        object_copy.is_negative = false;

        // Для экономии вычислений возвращаем нуль в случае, если правый операнд больше левого.
        if (this_copy < object_copy)
        {
            return new_object;
        }

        // Возвращаем нуль в случае, если правый операнд равен нулю.
        if (object_copy == zero)
        {
            std::cout << "Вы обнаружили пасхалку, поздравляю! Но на ноль делить нельзя." << std::endl;
            return new_object;
        }

        // Поиск позиции крайней правой цифры объекта this_copy.
        while (this_copy.container[first] == '.')
        {
            first--;
        }

        // Поиск позиции крайней правой цифры объекта object_copy.
        // Инициализация указателя, куда ставятся нули, позицией правой крайней цифры данного объекта.
        while (object_copy.container[second] == '.')
        {
            second--;
        }
        cur_zero = second;

        // До тех пор, пока количество цифр во втором числе не сравняется с количеством цифр в первом числе,
        // ставить в конец второго числа нули (умножать число object_copy на 10 до тех пор, пока оно по разрядности
        // не сравняется с числом this_copy).
        while (cur_zero < first)
        {
            cur_zero++;
            object_copy.container[cur_zero] = '0';
        }

        // До тех пор, пока в объекте object_copy сохраняются поставленные нами нули,
        // продолжать операцию деления.
        while (cur_zero >= second)
        {
            // Увеличение счетчика за каждую возможность вычесть из this_copy объект object_copy.
            counter = 0;
            while (this_copy >= object_copy)
            {
                this_copy = this_copy - object_copy;
                counter++;
            }

            // Полученное значение counter записывается на позицию iteration числа new_object.
            // При этом, если на позиции cur_zero объекта object_copy находится поставленный нами нуль, убираем его (делим число на 10).
            // Уменьшаем текущую позицию cur_zero на 1 и увеличиваем позицию iteration на 1.
            new_object.container[iteration] = '0' + counter;
            if (cur_zero != second)
            {
                object_copy.container[cur_zero] = '.';
            }

            // Переходим к следующему разряду числа new_object.
            cur_zero--;
            iteration++;
        }

        // Замена всех ведущих нулей на точки до первого ненулевого значения.
        // Если все цифры были нулевыми, то rescuer == this->max_length.
        while((new_object.container[rescuer] == '0') && (rescuer < this->max_length))
        {
            new_object.container[rescuer] = '.';
            rescuer++;
        }

        // Перенос значений с конца массива container объекта new_object в его начало.
        // Не выполняется, если число занимает весь массив либо число равно 0.
        if (rescuer != 0)
        {
            for(int pos = 0; rescuer < this->max_length; pos++)
            {
                new_object.container[pos] = new_object.container[rescuer];
                new_object.container[rescuer] = '.';

                rescuer++;
            }
        }


        /* Если результат является ненулевым и первое число является отрицательным,
         * то увеличить модуль результата на единицу.

         * Пояснение:
         * Если a / b = c (где sign(c) =  sign(a) * sign(b))
         * И    a > 0,
         * То   (-a) / b = -sign(c) * (|c| + 1)

         * Примеры:
         *  7 /  3 =  2; остаток 1
         *  7 / -3 = -2; остаток 1
         * -7 /  3 = -3; остаток 2
         * -7 / -3 =  3. остаток 2 */
        if ((this_copy.container[0] != '.') && (first_is_negative))
        {
            temp = new_object.is_negative;
            new_object = new_object.abs();
            new_object = new_object + one;
            new_object.is_negative = temp;
        }

        return new_object;
    }

    Extended_oct_number operator%(Extended_oct_number& object)
    /* Оператор получения остатка от целочисленного деления.
     * Возвращает остаток от целочисленного деления восьмеричного числа *this на object в виде нового объекта типа Extended_oct_number.
     * Параметры:
     *   Extended_oct_number &object    : левый операнд операции отстатка от целочисленного деления.
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, хранящее результат отстатка от целочисленного деления текущего объекта на объект object.
     */
    {
        // Создание возвращаемого значения, инициализированного нулем.
        Extended_oct_number new_object{false};

        // Пеерменная, необходимая для корректной проверки равенства нулю делителя object.
        Extended_oct_number zero{false};

        // Возвращаем нуль в случае, если правый операнд равен нулю.
        if (object == zero)
        {
            std::cout << "Вы обнаружили пасхалку, поздравляю! Но на ноль делить нельзя." << std::endl;
            return new_object;
        }

        // Результат целочисленного деления *this / object.
        Extended_oct_number multiplier{*this / object};

        // Если multiplier * object + new_object = *this, то new_object = *this - multiplier * object.

        // Промежуточная операция для вычисления второго слагаемого.
        multiplier = multiplier * object;

        // Вычисление результата.
        new_object = *this - multiplier;

        return new_object;
    }

    Extended_oct_number operator+()
    /* Унарный плюс.
     * Возвращает восьмеричное число, созданное на базе текущего объекта, с сохранением знака.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, аналогичное текущему объекту, с сохраненным знаком.
     */
    {
        Extended_oct_number new_object{*this};
        new_object.is_negative = this->is_negative;
        return new_object;
    }

    Extended_oct_number operator-()
    /* Унарный минус.
     * Возвращает восьмеричное число, созданное на базе текущего объекта, с инверсией знака.
     * Параметры:
     *   Нет
     * Возвращаемое значение:
     *   Extended_oct_number new_object : число, аналогичное текущему объекту, с инверсированным знаком.
     */
    {
        Extended_oct_number new_object{*this};
        new_object.is_negative = !(this->is_negative);
        return new_object;
    }

    bool operator >(Extended_oct_number& object)
    /* Оператор сравнения "больше".
     * Возвращает true, если левый операнд хранит число, большее, чем число, хранящееся в правом операнде, и false в противном случае.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool this_is_higher         : результат сравнения.
     */
    {
        // Инициализация:
        // > метки, указывающей, является ли число *this наибольшим;
        // > метки, указывающей, нужно ли пропускать операции сравнения двух цифр;
        // > метки, указывающей, нужно ли инвертировать результат сравнения (true, если оба числа отрицательны).
        bool this_is_higher{true}, skip{false}, reverse{false};

        // Если первое число положительно, а второе - отрицательно, вернуть true.
        if ((this->is_negative == false) && (object.is_negative == true))
        {
            return true;
        }
            // Иначе, если первое число отрицательно, а второе - положительно, вернуть false.
        else if ((this->is_negative == true) && (object.is_negative == false))
        {
            return false;
        }
            // Иначе, если оба числа отрицательны, инвертировать резельтат сравнения по модулю.
        else if ((this->is_negative == true) && (object.is_negative == true))
        {
            reverse = true;
        }
        // Иначе [оба числа положительны, инвретировать ничего не нужно, случай учтен при инициализации]

        // Пробегаемся по всем элементам массивов container обоих чисел.
        for (int pos = 0; pos < this->max_length; pos++)
        {
            // Если оба элементы являются точками, сравнение закончено (т. к. результат известен).
            if ((this->container[pos] == '.') && (object.container[pos] == '.'))
            {
                break;
            }
                // Иначе если второе число закончилось раньше, сравнение закончено (первое число больше).
            else if ((this->container[pos] != '.') && (object.container[pos] == '.'))
            {
                this_is_higher = true;
                break;
            }
                // Иначе если первое число закончено раньше, сравнение закончено (второе число больше).
            else if ((this->container[pos] == '.') && (object.container[pos] != '.'))
            {
                this_is_higher = false;
                break;
            }
                // Иначе у обоих чисел на данной позции имеются цифры, и...

                // ..если цифра первого числа больше цифры второго, то при равной разрядности первое число будет больше.
                // Остальные цифры можно не сравнивать - нужно проверить только разрядность чисел.
            else if ((this->container[pos] > object.container[pos]) && !(skip))
            {
                this_is_higher = true;
                skip = true;
                continue;
            }
                // ...если цифра первого числа равна цифре второго, то ничего сказать нельзя.
                // Если до этого все остальные цифры также были равны, то считается, что (*this == object) = true.
            else if ((this->container[pos] == object.container[pos]) && !(skip))
            {
                this_is_higher = false;
                continue;
            }

                // ...если мы не пропускаем проверку, то цифра первого числа меньше цифры второго и при равной
                // разрядности второе число будет больше.
                // Остальные цифры можно не сравнивать - нужно проверить только разрядность чисел.
            else if (!(skip))
            {
                this_is_higher = false;
                skip = true;
            }

        }

        // Если оба числа отрицательны, то меняем результат сравнения на протиположный.
        if (reverse)
        {
            this_is_higher = !this_is_higher;
        }

        return this_is_higher;
    }

    bool operator ==(Extended_oct_number& object)
    /* Оператор сравнения "равно".
     * Возвращает true, если числа, хранящиеся в обоих операндах, равны, и false в противном случае.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения.
     */
    {
        // Объявление возвращаемой метки.
        bool result{false};

        // Если знаки чисел не совпадают, то сразу вернуть false.
        if (this->is_negative != object.is_negative)
        {
            return result;
        }

        // Сравнение соответствующих символов в массивах container обоих чисел.
        for (int i = 0; i < max_length - 1; i++)
        {
            // Если находится хотя бы одно отличие, возвращается false.
            if (this->container[i] != object.container[i])
            {
                return result;
            }
        }

        // Если знаки чисел равны, а их массивы container содержат одинаковые знаки,
        // возвращается true.
        result = true;
        return result;
    }

    bool operator !=(Extended_oct_number& object)
    /* Оператор сравнения "не равно".
     * Возвращает true, если числа, хранящиеся в обоих операндах, не равны, и false в противном случае.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return !(*this == object);
    }

    bool operator >=(Extended_oct_number& object)
    /* Оператор сравнения "больше либо равно".
     * Возвращает true, если число, хранящееся в левом операнде, больше либо равно числу,
     * хранящемуся в правом операнде.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return ((*this > object) || (*this == object));
    }

    bool operator <(Extended_oct_number& object)
    /* Оператор сравнения "меньше".
     * Возвращает true, если число, хранящееся в левом операнде, меньше числа, хранящегося в правом операнде.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return (!(*this >= object));
    }

    bool operator <=(Extended_oct_number& object)
    /* Оператор сравнения "меньше либо равно".
     * Возвращает true, если число, хранящееся в левом операнде, меньше либо равно числу,
     * хранящемуся в правом операнде.
     * Параметры:
     *   Extended_oct_number& object : правый операнд, восьмеричное число.
     * Возвращаемое значение:
     *   bool                        : результат сравнения
     */
    {
        return (!(*this > object));
    }

};

int main()
{
    // Кириллица в консоли.
    RUSSIAN;

    // Ответ пользователя на запрос.
    std::string answer;

    // Второстепенное восмеричное число.
    Oct_number second_number_oct{false};

    // Главное число, второстепенное расширенное восьмеричное число и результат арифметической операции.
    Extended_oct_number the_number{true}, second_number{false}, result{false};

    CLS;

    // Реализация пользовательского интерфейса для взаимодействия с функционалом класса Extended_oct_number.
    while (true)
    {
        bool not_okay = true;

        // Запрашивать пользовательский ввод до введения корректного ответа.
        while (not_okay)
        {
            // Считать, что введенный ответ является корректным, до первой ошибки.
            not_okay = false;

            std::cout << "Текущее число: ";
            the_number.Print_number();
            std::cout << "1. Чтение нового левого операнда." << std::endl;
            std::cout << "2. (+)  Сложение текущего числа с другим." << std::endl;
            std::cout << "3. (-)  Вычитание из текущего числа другого." << std::endl;
            std::cout << "4. (*)  Умножение текущего числа на другое." << std::endl;
            std::cout << "5. (//) Целочисленное деление текущего числа на другое." << std::endl;
            std::cout << "6. (%)  Получение остатка от целочисленного деления текущего числа на другое." << std::endl;
            std::cout << "7. Вызов неперегруженной функции cosh()." << std::endl;
            std::cout << "8. Вызов перегруженной функции cosh()." << std::endl;
            std::cout << "9. Выход из программы." << std::endl;

            std::cout << "Введите операцию для выполнения: ";
            std::cin >> answer;

            // Запрос операции некорректен, если ответ содержит больше одного символа.
            if (answer.length() > 1)
            {
                std::cout << "Введена некорректная операция." << std::endl;
                not_okay = true;

                approve();
                continue;
            }

            // Запрос операции некорректен, если ответ не является числом.
            for (auto c : answer)
            {
                if (!(('0' <= c) && (c <= '9')))
                {
                    std::cout << "Введена некорректная операция." << std::endl;
                    not_okay = true;
                    approve();
                    break;
                }
            }
        }

        // Если пользователь вводит выход из програмы, то цикл пользовательского интерфейса завершается.
        if (std::stoi(answer) == 9)
        {
            std::cout << "Выход из программы..." << std::endl;
            break;
        }

        CLS;

        // Выбор поведения в зависимости от ответа пользователя.
        switch (std::stoi(answer))
        {
            case 1:
            {
                std::cout << "Текущее число: ";
                the_number.Print_number();
                the_number.Change_number();

                break;
            }

            case 2:
            {
                std::cout << "Операция: +" << std::endl;
                std::cout << "Левый операнд: ";
                the_number.Print_number();
                second_number.Change_number();
                result = the_number + second_number;
                the_number.Print_for_equaution();
                std::cout << " + ";
                second_number.Print_for_equaution();
                std::cout << " = ";
                result.Print_for_equaution(true);
                break;
            }

            case 3:
            {
                std::cout << "Операция: -" << std::endl;
                std::cout << "Левый операнд: ";
                the_number.Print_number();
                second_number.Change_number();
                result = the_number - second_number;
                the_number.Print_for_equaution();
                std::cout << " - ";
                second_number.Print_for_equaution();
                std::cout << " = ";
                result.Print_for_equaution(true);
                break;
            }

            case 4:
            {
                std::cout << "Операция: *" << std::endl;
                std::cout << "Левый операнд: ";
                the_number.Print_number();
                second_number.Change_number();
                result = the_number * second_number;
                the_number.Print_for_equaution();
                std::cout << " * ";
                second_number.Print_for_equaution();
                std::cout << " = ";
                result.Print_for_equaution(true);
                break;
            }

            case 5:
            {
                std::cout << "Операция: //" << std::endl;
                std::cout << "Левый операнд: ";
                the_number.Print_number();
                second_number.Change_number();
                result = the_number / second_number;
                the_number.Print_for_equaution();
                std::cout << " // ";
                second_number.Print_for_equaution();
                std::cout << " = ";
                result.Print_for_equaution(true);
                break;
            }

            case 6:
            {
                std::cout << "Операция: %" << std::endl;
                std::cout << "Левый операнд: ";
                the_number.Print_number();
                second_number.Change_number();
                result = the_number % second_number;
                the_number.Print_for_equaution();
                std::cout << " % ";
                second_number.Print_for_equaution();
                std::cout << " = ";
                result.Print_for_equaution(true);
                break;
            }

            case 7:
            {
                not_okay = true;

                while (not_okay)
                {
                    not_okay = false;

                    std::cout << "Операция: cosh() (неперегруженная)." << std::endl;
                    std::cout << "Выберите тип числа:" << std::endl;
                    std::cout << "\t1. Восьмеричное число." << std::endl;
                    std::cout << "\t2. Расширенное восьмеричное число." << std::endl;
                    std::cout << "Введите восьмеричное число для проведения операции: ";
                    std::cin >> answer;

                    // Запрос операции некорректен, если ответ содержит больше одного символа.
                    if (answer.length() > 1)
                    {
                        std::cout << "Введена некорректная операция." << std::endl;
                        not_okay = true;

                        approve();
                        continue;
                    }

                    // Запрос операции некорректен, если ответ не является числом.
                    for (auto c : answer)
                    {
                        if (!(('0' < c) && (c < '3')))
                        {
                            std::cout << "Введена некорректная операция." << std::endl;
                            not_okay = true;
                            approve();
                            break;
                        }
                    }

                }

                switch(std::stoi(answer))
                {
                    case 1:
                    {
                        second_number_oct.Change_number();
                        std::cout << "cosh(";
                        second_number_oct.Print_number(false);
                        std::cout << ") = " << second_number_oct.cosh() << std::endl;
                        break;
                    }

                    case 2:
                    {
                        second_number.Change_number();
                        std::cout << "cosh(";
                        second_number.Print_number(false);
                        std::cout << ") = " << second_number.cosh() << std::endl;
                        break;
                    }

                    default:
                    {
                        std::cout << "Введена некорректная операция." << std::endl;
                    }
                }

                break;
            }

            case 8:
            {
                std::cout << "Операция: cosh() (перегруженная)" << std::endl;
                std::cout << "Выберите тип числа:" << std::endl;
                std::cout << "\t1. Восьмеричное число." << std::endl;
                std::cout << "\t2. Расширенное восьмеричное число." << std::endl;

                not_okay = true;
                while (not_okay)
                {
                    not_okay = false;
                    std::cout << "Введите восьмеричное число для проведения операции: ";
                    std::cin >> answer;

                    // Запрос операции некорректен, если ответ содержит больше одного символа.
                    if (answer.length() > 1)
                    {
                        std::cout << "Введена некорректная операция." << std::endl;
                        not_okay = true;

                        approve();
                        continue;
                    }

                    // Запрос операции некорректен, если ответ не является числом.
                    for (auto c : answer)
                    {
                        if (!(('0' <= c) && (c <= '9')))
                        {
                            std::cout << "Введена некорректная операция." << std::endl;
                            not_okay = true;
                            approve();
                            break;
                        }
                    }

                }

                switch(std::stoi(answer))
                {
                    case 1:
                    {
                        second_number_oct.Change_number();
                        std::cout << "cosh(";
                        second_number_oct.Print_number(false);
                        std::cout << ") ~= " << second_number_oct.cosh(false) << std::endl;
                        break;
                    }

                    case 2:
                    {
                        second_number.Change_number();
                        std::cout << "cosh(";
                        second_number.Print_number(false);
                        std::cout << ") ~= " << second_number.cosh(false) << std::endl;
                        break;
                    }
                    default:
                    {
                        std::cout << "Введена некорректная операция." << std::endl;
                    }
                }

                break;
            }

                // Если было введенно число, не попадающее в диапазон, операция считается недействительной.
            default:
            {
                std::cout << "Введена некорректная операция." << std::endl;
            }
        }

        approve();
    }

    return 0;
}

// Функция для подтверждения любого действия пользователя (продолжения работы с программой).
void approve()
{
    char enter{'.'};

    std::cout << "Нажмите Enter для продолжения..." << std::endl;
    while (enter != '\r')
    {
        enter = _getch();
        std::cout << enter;
    }
    CLS;
}

// Функция для вычисления факториала.
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (factorial(n - 1) < INT_MAX / n)
        {
            return n * factorial(n - 1);
        }
        else
        {
            std::cout << "Произошло переполнение. Операция не была выполнена" << std::endl;
            return -1;
        }
    }
}