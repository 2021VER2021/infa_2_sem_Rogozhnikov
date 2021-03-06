import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
Z =[
[
[1.99735,4,0],
[3.2639,5,0],
[4.83592,6,0],
[6.68434,7,0],
[8.78541,8,0],
[11.2062,9,0],
[13.928,10,0],
[16.8261,11,0],
[20.0003,12,0],
[23.6203,13,0],
[27.2673,14,0],
[31.4865,15,0],
[35.9275,16,0],
[40.4912,17,0],
[45.3507,18,0],
[50.3745,19,0],
],
[
[2.49277,4,0.25],
[4.08959,5,0.25],
[6.02292,6,0.25],
[8.33048,7,0.25],
[11.0134,8,0.25],
[13.9281,9,0.25],
[17.3347,10,0.25],
[20.9946,11,0.25],
[25.1331,12,0.25],
[29.4276,13,0.25],
[34.3728,14,0.25],
[39.2922,15,0.25],
[44.8581,16,0.25],
[50.7006,17,0.25],
[56.4036,18,0.25],
[63.2364,19,0.25],
],
[
[2.99558,4,0.4],
[4.8922,5,0.4],
[7.22021,6,0.4],
[10.0327,7,0.4],
[13.1389,8,0.4],
[16.8535,9,0.4],
[20.8004,10,0.4],
[25.1609,11,0.4],
[30.0111,12,0.4],
[35.4118,13,0.4],
[41.4293,14,0.4],
[47.07,15,0.4],
[53.7591,16,0.4],
[60.4653,17,0.4],
[68.0277,18,0.4],
[75.9586,19,0.4],
],
[
[3.50266,4,0.5],
[5.76154,5,0.5],
[8.43731,6,0.5],
[11.6885,7,0.5],
[15.3981,8,0.5],
[19.5379,9,0.5],
[24.1277,10,0.5],
[29.4005,11,0.5],
[35.0798,12,0.5],
[41.0141,13,0.5],
[47.9671,14,0.5],
[54.9917,15,0.5],
[62.7223,16,0.5],
[70.9326,17,0.5],
[79.2438,18,0.5],
[88.2664,19,0.5],
],
[
[4.018,4,0.571429],
[6.58503,5,0.571429],
[9.69573,6,0.571429],
[13.3526,7,0.571429],
[17.4887,8,0.571429],
[22.3717,9,0.571429],
[27.6906,10,0.571429],
[33.3411,11,0.571429],
[40.2018,12,0.571429],
[46.8612,13,0.571429],
[54.9703,14,0.571429],
[62.4265,15,0.571429],
[71.3439,16,0.571429],
[81.0153,17,0.571429],
[90.068,18,0.571429],
[100.569,19,0.571429],
],
[
[4.49961,4,0.625],
[7.34702,5,0.625],
[10.8363,6,0.625],
[14.9446,7,0.625],
[19.7432,8,0.625],
[25.1296,9,0.625],
[31.0118,10,0.625],
[37.888,11,0.625],
[45.1536,12,0.625],
[53.1739,13,0.625],
[61.3424,14,0.625],
[70.7041,15,0.625],
[80.2232,16,0.625],
[90.5492,17,0.625],
[101.628,18,0.625],
[113.925,19,0.625],
],
[
[5.00884,4,0.666667],
[8.18898,5,0.666667],
[12.0238,6,0.666667],
[16.6406,7,0.666667],
[21.9291,8,0.666667],
[27.8631,9,0.666667],
[34.5635,10,0.666667],
[42.2451,11,0.666667],
[49.813,12,0.666667],
[58.6927,13,0.666667],
[67.7939,14,0.666667],
[78.0498,15,0.666667],
[88.9452,16,0.666667],
[100.699,17,0.666667],
[113.161,18,0.666667],
[126.635,19,0.666667],
],
[
[5.47048,4,0.7],
[9.0011,5,0.7],
[13.2329,6,0.7],
[18.3257,7,0.7],
[24.1695,8,0.7],
[30.7209,9,0.7],
[38.3006,10,0.7],
[46.1341,11,0.7],
[55.2482,12,0.7],
[65.0489,13,0.7],
[74.9735,14,0.7],
[86.0526,15,0.7],
[98.2686,16,0.7],
[110.862,17,0.7],
[125.551,18,0.7],
[138.783,19,0.7],
],
[
[6.01059,4,0.727273],
[9.85468,5,0.727273],
[14.4796,6,0.727273],
[20.0972,7,0.727273],
[26.4033,8,0.727273],
[33.4133,9,0.727273],
[41.6722,10,0.727273],
[50.3602,11,0.727273],
[60.261,12,0.727273],
[70.8537,13,0.727273],
[81.966,14,0.727273],
[94.3294,15,0.727273],
[107.506,16,0.727273],
[121.852,17,0.727273],
[135.602,18,0.727273],
[152.555,19,0.727273],
],
[
[6.52787,4,0.75],
[10.7266,5,0.75],
[15.7492,6,0.75],
[21.5607,7,0.75],
[28.6375,8,0.75],
[36.5158,9,0.75],
[45.0385,10,0.75],
[54.7915,11,0.75],
[65.1921,12,0.75],
[76.4695,13,0.75],
[88.6145,14,0.75],
[101.911,15,0.75],
[115.953,16,0.75],
[131.994,17,0.75],
[146.905,18,0.75],
[165.096,19,0.75],
]]
fig, ax = plt.subplots()#
plt.grid(True)
#  ?????????????????????????? ???????????????? ???????????????? ??????????????:
ax.xaxis.set_major_locator(ticker.MultipleLocator(100))
#  ?????????????????????????? ???????????????? ?????????????????????????????? ??????????????:
ax.xaxis.set_minor_locator(ticker.MultipleLocator(10))
#  ???????? ?????????? ?????????????????????? ?? ?????????????????? ???? ?????? "y":
ax.yaxis.set_major_locator(ticker.MultipleLocator(100))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(10))
#  ?????????????????? ?????????? ???????????????? ??????????:
ax.grid(which='major',
            color = 'k')
#  ???????????????? ?????????????????? ?????????????????????????????? ??????????????:
ax.minorticks_on()
#  ???????????? ?????????? ???????????????? ???????????????? ?????????????? ??????
#  ?????????????????????????????? ??????????:
ax.grid(which='minor',
        color = 'gray',
        linestyle = ':')
plt.xlabel('L^2, tiles^2')
plt.ylabel('T, steps')
p_arr = []
z = []
for j in range(len(Z)):
    x = []
    y = []
    for i in range(len(Z[j])):
        x.append(Z[j][i][1]**2)
        y.append(Z[j][i][0])
    p, v = np.polyfit(x, y, deg = 1, cov = True)
    func2 = np.poly1d(p)
    z2 = np.arange(0, 22*22, 0.1)
    plt.scatter(x, y)
    plt.plot(z2, func2(z2))
    p_arr.append(p[0])
    z.append(Z[j][0][2])
"""
z0 = np.arange(0, 0.8, 0.001)
plt.scatter(z, p_arr)

p, v = np.polyfit(z, p_arr, deg = 2, cov = True)
func2 = np.poly1d(p)
plt.plot(z0, func2(z0))
"""
plt.show()
print(p)
