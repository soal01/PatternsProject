# Расшифровка значков


## Игровое поле
Игровое поле представляет собой 400 клеток на каждой из которых отображается значком метности или юнита, который стоит на этой клетке.
### Значки местности
'?' - значок леса
'^' - значок гор
'_' - значок равнины
### Значки юнитов
'S' - пеший солдат 
'C' - кавалерист
'T' - танк
'B' - броневик
'A' - пушка

## Команды
Игрок взаимодействует с игровым полем при помощи следующих команд:
### move
Синтаксис: move x1 y1 x2 y2 
x1 и y1 - левая и верхняя соответственно координаты юнита, который будет ходить
x2 и y2 - левая и верхняя соответственно координаты куда юнит пойдет
Данная команда передвигает юнита в указанную клетку, если она свободна. Если она занята вражеским юнитом и он находится в зоне, которую может атаковать юнит, то происходит атака
### info 
Синтаксис: info x y
x и y - левая и верхняя соответственно координаты клетки, о которой вы хотите узнать информацию. Если на этой клетке стоит юнит то дополнительно еще узнаете информацию о юните
### buy
Синтаксис: buy x y type
x и y - левая и верхняя соответственно координаты клетки, куда поставят нового юнита
type - тип юнита:
0 - пеший солдат (стоит 50)
1 - кавалерист (стоит 75)
2 - танк (стоит 200)
3 - броневик (стоит 100)
4 - пушка (стоит 140)
Особенность заключается в том что игрок 1 не может ставить юнитов на горизонтали ниже 5-ой, а игрок 0 выше 15-ой горизонтали
### next_turn
Синтаксис: next_turn
Передает ход другому игроку. Восстанавливает здоровье и очки переждвижения другого игрока.