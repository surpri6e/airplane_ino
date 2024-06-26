# Airplane Ino


## P.S.

К моему несчастью данный репозиторий был удален и восстановлен лишь документационный файл, с которым вы можете ознакомиться. Исходный код потерян.

## Main

Данный репозиторий был создан для совсместной комфортной работы над проектом. В данном файле(README.md) будет размещена основная полезная справочная информация по работе т.е. все информационные ресурсы будут размещены здесь. В остальных папках будет виден основной код, который разрабатывался для программирования платы.

Для начала поместим все основные ссылки:

- [Основной сайт с правочной информацие платы](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:strela)
- [Русская справочна инофрмаци по Arduino](http://arduino.ru/Reference)
- [Справочная информация по ШИМ](http://wiki.amperka.ru/%D0%BA%D0%BE%D0%BD%D1%81%D0%BF%D0%B5%D0%BA%D1%82-arduino:%D1%88%D0%B8%D0%BC)
- [Сенсоры с цифровым сигналом](http://wiki.amperka.ru/%D1%81%D0%B5%D0%BD%D1%81%D0%BE%D1%80%D1%8B:%D1%86%D0%B8%D1%84%D1%80%D0%BE%D0%B2%D1%8B%D0%B5)
- [Сенсоры с аналоговым сигналом](http://wiki.amperka.ru/%D1%81%D0%B5%D0%BD%D1%81%D0%BE%D1%80%D1%8B:%D0%B0%D0%BD%D0%B0%D0%BB%D0%BE%D0%B3%D0%BE%D0%B2%D1%8B%D0%B5)

## Images

**Раздел с основной иформацией о плате**

Основные соответствия контактов на плате - *Таблица*.

Основная схема платы, расположение элементов платы - *Схема*.

Контакты специального назначения на плате - *Таблица*.

Расширители портов на плате - *Схема*.

**Дополнительный раздел для удобства**

Таблица истинности - *Таблица*.

## Strela

### Отличия библиотеки <Strela.h> от стандартного Arduino

Самые главные отличия лежат в основе работы с портами, контактами и пинами соответственно. Платформа Strela имеет на борту контакты подключённые к Arduino-микроконтроллеру и контакты подключённые к **I²C-расширителю** портов ввода-вывода. На аппаратном уровне доступ к этим портам ввода-вывода очень сильно различается, но библиотека <Strela.h> позволяет облегчить данную задачу. Разница в управлении контактами Arduino и контактами **I²C-расширителей** портов отсутствует, если использовать функции `uPinMode`, `uDigitalWrite` и `uDigitalRead`. Конечно, можно использовать и привычные функции управления цифровыми контактами, но они будут работать только с Arduino-контактами. Также просмотрев репозитории на GitHub и командные файлы, увидел, что были добавлены новые функции в работу с Arduino, такие как: `drive`, `motorSpeed`, `motorConnection`, `stepperMotor`. Подробнее о них напишу по ходу изучения и практики работы с ними.


В остальном же все и так совместимо работает т.е. это основные и главный изменения, которые вносит разработанная библиотека, по крайней мере это все различия, которые я смог найти прочитав документацию к плате(см. в полезных ссылках) и просмотрев их репозиторий на GitHub.

### <Wire.h> в жизни <Strela.h>

С пункта выше может созреть вопрос - "В чем же различия этих двух принципиальных библиотек?". Раставим все по полочкам.

- **<Wire.h>**. Наиболее подходящая документация к использованию - [ТЫК](https://all-arduino.ru/biblioteki-arduino/arduino-biblioteka-wire/). Данная библиотека позволяет нам связывать микроконтроллеры с устройствами и модулями через интерфейс I²C т.е. ее задача находить эти самые расширители, а также находить устройства, подключенные через этот расширитель.
- **<Strela.h>**. Данная же библиотека позволяет нам работать с устройствами, которые были найдены через данный интерфейс, задавать им различнные задания, программы и функции т.е. удобное функционнирование с устройствами.

### Взаимодействие контактов и пинов

Взамодействие пинов, контактов между собой происходит при помощи основных команд, функций заложенных в Arduino и при помощи библиотеки <Strela.h>.

### Подключение библиотек

Подключение библиотек происходит следующим способом:

```c++
#include <Strela.h>
#include <Wire.h>
```

## Arduino

### Примеры программ

Здесь будут размещены интересные программы, которые помогут понять суть некоторых алгоритмов и их предназначения. Они как могут использоваться в исходном коде, так и не могут - зависит от сути команды. На первом этапе они помогут лучше познакомиться с Arduino и библиотеками. Некоторые программы я взял с репозитория на GitHub, некоторые же сделал сам. Примеры самих разработчиков с объяснениями - [ТЫК](https://github.com/amperka/Strela/tree/master/Strela/Examples)

Алгорит №1. Считывает положение кнопки при нажатии и включает светодиод с тем же номером что и кнопка.

Разбор алгоритма. Мы входим в цикл **for** и в переменную **i** кладем значение кнопки S1, проходим через условие `i <= S4`. В buttonNumber кладем положение этой кнопки(их у нас всего 4), в переменную **buttunState** кладем состояние это кнопки т.е. нажата она или нет при помощи функции `uDigitalRead()`, а далее при помощи последеней функции(она довольна сложна в алгоритмическом понятии, разберем её в следующем блоке) первым аргументом проверяем положение этой кнопки, а вторым её аргументом - состояние - нажата или нет, если она нажата, то зажигаем светодиод с таким же положением.

```c++
#include <Wire.h>
#include <Strela.h>

void setup() {
}

void loop() {
  for (byte i = S1; i <= S4; ++i) { 
    byte buttonNumber = i - S1;
    bool buttonState = uDigitalRead(i);
    uDigitalWrite(L1 + buttonNumber, buttonState);
  }
}
```

Примечания. Под условными константами S1, S2, S3, S4, да и вообще под всеми условными константами скрываются какие-то целочисленные значения, которые заменили для удобного использования - подверждение моим словам - фрагмент кода с репозитория. Где это можно найти - [ТЫК](https://github.com/amperka/Strela/blob/master/Strela/Strela.h). Ещё раз посмотрим на код, сначала i = S1 т.е. 50; 50 <= 53; i = 50. Тогда buttenNumber = 50 - 50 = 0; buttonState проверят состояние этой кнопки при поиощи `uDigitalRead(i)` т.е. кнопку S1 = 50. И последнее, самое сложное `uDigitalWrite`. Для начала поймем, что в L1, L2, L3, L4 хранятся похожие значения что и в кнопках т.е. идущие подряд по **натуральному порядку**. Мы берем самый первый светодиод, а точнее его значение, будет отталкиваться от него, к L1 в нашем случае мы прибавляем 0 т.е. так и остается просто L1, без изменений. Второе - если кнопка S1 была нажата, то buttonState будет в состоянии "нажатом". Обобщим, `uDigitalWrite(в нашем случае просто L1, к примеру - нажат)` т.е. команда будет выполнена - светодиод L1 загориться. Такую же аналогию можно проводить и дальше по циклу с S2, S3 и т.д. её я расписывать не буду, потому что она такая же как и здесь.

```c++
#define S1 50
#define S2 51
#define S3 52
#define S4 53
```

Мои правки и изменения. Во-первых, изменил тип переменой **byte** на другой. Во-вторых, значительно снизил густоту кода и увеличил его простоту и понятность. В-третьих, самое главное - убрал 2 ненужных переменных, которые в общей сложности занимают 2 байта памяти и 2 байта ОЗУ т.е. оптимизировал код, сделал его быстрее, очистил от мусора и ненужной хранящейся информации.

```c++
#include <Wire.h>
#include <Strela.h>

void setup() {

}

void loop() {
  for(uint8_t i = S1; i <= S4; i++) {
    uDigitalWrite(L1 + (i - S1), uDigitalRead(i));
  }
}
```

---

## License

See [the LICENSE file](./LICENSE).

Regards *surpri6e*.