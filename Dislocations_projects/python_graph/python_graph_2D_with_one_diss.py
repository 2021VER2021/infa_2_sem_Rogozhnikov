import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
Z =[
[1,3],
[2.0033,4],
[3.2373,5],
[4.856,6],
[6.7637,7],
[8.7009,8],
[11.2262,9],
[14.1086,10],
[16.445,11],
[19.9601,12],
[23.1099,13],
[27.39,14],
[31.5743,15],
[35.6878,16],
[40.4908,17],
[45.5918,18],
[49.8303,19],
[55.5977,20],
[62.2725,21],
[68.3672,22],
[74.7823,23],
[80.9356,24],
[86.6088,25],
[95.7153,26],
[101.817,27],
[108.681,28],
[120.042,29],
[125.958,30],
[136.622,31],
[143.661,32],
[156.275,33],
[160.876,34],
[166.063,35],
[184.083,36],
[194.407,37],
[202.292,38],
[215.806,39],
[227.665,40],
[236.68,41],
[250.196,42],
[260.476,43],
[269.169,44],
[284.857,45],
[292.397,46],
[304.087,47],
[319.431,48],
[341.447,49],
[360.529,50],
[362.906,51],
[378.038,52],
[390.123,53],
[406.282,54],
[428.544,55],
[444.874,56],
[461.449,57],
[473.785,58]
]
x = []
y = []
for i in range(len(Z)):
    x.append(Z[i][1]**2)
    y.append(Z[i][0])
fig, ax = plt.subplots()#
plt.grid(True)
#  Устанавливаем интервал основных делений:
ax.xaxis.set_major_locator(ticker.MultipleLocator(1000))
#  Устанавливаем интервал вспомогательных делений:
ax.xaxis.set_minor_locator(ticker.MultipleLocator(100))
#  Тоже самое проделываем с делениями на оси "y":
ax.yaxis.set_major_locator(ticker.MultipleLocator(100))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(10))
#  Добавляем линии основной сетки:
ax.grid(which='major',
        color = 'k')
#  Включаем видимость вспомогательных делений:
ax.minorticks_on()
#  Теперь можем отдельно задавать внешний вид
#  вспомогательной сетки:
ax.grid(which='minor',
        color = 'gray',
        linestyle = ':')

plt.xlabel('L^2, tiles^2')
plt.ylabel('T, steps')
p, v = np.polyfit(x, y, deg = 1, cov = True)
func2 = np.poly1d(p)
z2 = np.arange(0, 59*59, 0.1)
plt.scatter(x, y)
plt.plot(z2, func2(z2))

print(p)
plt.show()

