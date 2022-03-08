import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
Z = [
[4.00839,4,0],
[6.66445,5,0],
[9.96137,6,0],
[14.0023,7,0],
[18.697,8,0],
[23.9295,9,0],
[30.0029,10,0],
[36.7892,11,0],
[44.001,12,0],
[51.9615,13,0],
[60.8144,14,0],
[70.3067,15,0],
[79.982,16,0],
[91.0159,17,0],
[102.328,18,0],
[113.754,19,0]
]
fig, ax = plt.subplots()#
plt.grid(True)
#  Устанавливаем интервал основных делений:
ax.xaxis.set_major_locator(ticker.MultipleLocator(100))
#  Устанавливаем интервал вспомогательных делений:
ax.xaxis.set_minor_locator(ticker.MultipleLocator(10))
#  Тоже самое проделываем с делениями на оси "y":
ax.yaxis.set_major_locator(ticker.MultipleLocator(50))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(5))
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
x = []
y = []
for i in range(len(Z)):
    x.append(Z[i][1]**2)
    y.append(Z[i][0])
p, v = np.polyfit(x, y, deg = 1, cov = True)
func2 = np.poly1d(p)
z2 = np.arange(0, 22*22, 0.1)
plt.scatter(x, y)
plt.plot(z2, func2(z2))
plt.show()
print(p)
