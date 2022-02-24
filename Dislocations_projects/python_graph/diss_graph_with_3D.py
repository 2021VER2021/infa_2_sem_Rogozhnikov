import pylab
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import numpy as np
# X - crystal area; Y - diss area; Z - data from C++ program
X = [9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169]
Y = list(np.arange(1, 122, 1))
Z = [
[1,1,9],
[2.0066,1,16],
[1.8016,2,16],
[1.4613,3,16],
[1.1776,4,16],
[3.2743,1,25],
[3.1619,2,25],
[2.6414,3,25],
[2.1408,4,25],
[1.8199,5,25],
[1.5179,6,25],
[1.3083,7,25],
[1.1661,8,25],
[1.0579,9,25],
[4.8354,1,36],
[5.04924,2,36],
[4.46222,3,36],
[3.79841,4,36],
[3.24452,5,36],
[2.78155,6,36],
[2.42722,7,36],
[2.12707,8,36],
[1.89909,9,36],
[1.70747,10,36],
[1.54879,11,36],
[1.40851,12,36],
[1.29113,13,36],
[1.19165,14,36],
[1.10963,15,36],
[1.04443,16,36],
[6.67953,1,49],
[7.35877,2,49],
[6.90252,3,49],
[6.143,4,49],
[5.38276,5,49],
[4.73616,6,49],
[4.18424,7,49],
[3.71248,8,49],
[3.31831,9,49],
[3.00553,10,49],
[2.71008,11,49],
[2.47503,12,49],
[2.26983,13,49],
[2.09056,14,49],
[1.93169,15,49],
[1.79485,16,49],
[1.66867,17,49],
[1.55557,18,49],
[1.45609,19,49],
[1.36097,20,49],
[1.2763,21,49],
[1.20148,22,49],
[1.13899,23,49],
[1.08478,24,49],
[1.04019,25,49],
[8.80644,1,64],
[10.1244,2,64],
[9.8547,3,64],
[9.09866,4,64],
[8.17807,5,64],
[7.37253,6,64],
[6.60509,7,64],
[5.96263,8,64],
[5.42726,9,64],
[4.9193,10,64],
[4.48774,11,64],
[4.10506,12,64],
[3.7899,13,64],
[3.48611,14,64],
[3.22946,15,64],
[2.99946,16,64],
[2.79069,17,64],
[2.61085,18,64],
[2.44185,19,64],
[2.29323,20,64],
[2.1652,21,64],
[2.03244,22,64],
[1.92106,23,64],
[1.81922,24,64],
[1.71975,25,64],
[1.63251,26,64],
[1.54867,27,64],
[1.47057,28,64],
[1.3947,29,64],
[1.32418,30,64],
[1.26283,31,64],
[1.20695,32,64],
[1.15776,33,64],
[1.11065,34,64],
[1.07207,35,64],
[1.03975,36,64],
[11.1544,1,81],
[13.3117,2,81],
[13.3703,3,81],
[12.5961,4,81],
[11.6807,5,81],
[10.6951,6,81],
[9.79886,7,81],
[8.91714,8,81],
[8.13933,9,81],
[7.4917,10,81],
[6.91504,11,81],
[6.37703,12,81],
[5.90481,13,81],
[5.47977,14,81],
[5.09967,15,81],
[4.7542,16,81],
[4.42497,17,81],
[4.14137,18,81],
[3.8842,19,81],
[3.65172,20,81],
[3.43759,21,81],
[3.23456,22,81],
[3.06405,23,81],
[2.88906,24,81],
[2.74673,25,81],
[2.61634,26,81],
[2.47637,27,81],
[2.36685,28,81],
[2.2584,29,81],
[2.15168,30,81],
[2.0545,31,81],
[1.97476,32,81],
[1.88867,33,81],
[1.81412,34,81],
[1.73621,35,81],
[1.66199,36,81],
[1.59508,37,81],
[1.536,38,81],
[1.46884,39,81],
[1.40849,40,81],
[1.35478,41,81],
[1.29915,42,81],
[1.25362,43,81],
[1.20524,44,81],
[1.16489,45,81],
[1.12708,46,81],
[1.09302,47,81],
[1.06367,48,81],
[1.03873,49,81],
[13.8793,1,100],
[16.9447,2,100],
[17.4258,3,100],
[16.7941,4,100],
[15.8195,5,100],
[14.697,6,100],
[13.5168,7,100],
[12.522,8,100],
[11.5468,9,100],
[10.7259,10,100],
[9.9623,11,100],
[9.26255,12,100],
[8.61573,13,100],
[8.05168,14,100],
[7.56761,15,100],
[7.0681,16,100],
[6.63872,17,100],
[6.24013,18,100],
[5.886,19,100],
[5.53649,20,100],
[5.24221,21,100],
[4.93565,22,100],
[4.69086,23,100],
[4.43336,24,100],
[4.19789,25,100],
[3.99702,26,100],
[3.79362,27,100],
[3.62875,28,100],
[3.44336,29,100],
[3.28109,30,100],
[3.14684,31,100],
[3.01353,32,100],
[2.88567,33,100],
[2.76268,34,100],
[2.65416,35,100],
[2.54919,36,100],
[2.45752,37,100],
[2.36685,38,100],
[2.2839,39,100],
[2.20351,40,100],
[2.12165,41,100],
[2.05029,42,100],
[1.98417,43,100],
[1.91703,44,100],
[1.85545,45,100],
[1.79842,46,100],
[1.73447,47,100],
[1.67357,48,100],
[1.6201,49,100],
[1.56262,50,100],
[1.51311,51,100],
[1.46547,52,100],
[1.41288,53,100],
[1.36746,54,100],
[1.32271,55,100],
[1.28379,56,100],
[1.24227,57,100],
[1.20671,58,100],
[1.16954,59,100],
[1.13852,60,100],
[1.10938,61,100],
[1.08537,62,100],
[1.05957,63,100],
[1.03879,64,100],
[16.858,1,121],
[20.9758,2,121],
[22.0298,3,121],
[21.5784,4,121],
[20.4997,5,121],
[19.1966,6,121],
[18.0669,7,121],
[16.7742,8,121],
[15.6736,9,121],
[14.6249,10,121],
[13.6523,11,121],
[12.8087,12,121],
[11.9859,13,121],
[11.2436,14,121],
[10.5912,15,121],
[9.94663,16,121],
[9.44187,17,121],
[8.90289,18,121],
[8.43095,19,121],
[7.98694,20,121],
[7.53888,21,121],
[7.1651,22,121],
[6.79268,23,121],
[6.46193,24,121],
[6.1457,25,121],
[5.86894,26,121],
[5.59883,27,121],
[5.32549,28,121],
[5.1161,29,121],
[4.88596,30,121],
[4.66346,31,121],
[4.47645,32,121],
[4.28248,33,121],
[4.10344,34,121],
[3.95304,35,121],
[3.79651,36,121],
[3.64073,37,121],
[3.5061,38,121],
[3.39107,39,121],
[3.25306,40,121],
[3.13872,41,121],
[3.02523,42,121],
[2.91246,43,121],
[2.81629,44,121],
[2.72982,45,121],
[2.63978,46,121],
[2.5636,47,121],
[2.47576,48,121],
[2.40314,49,121],
[2.34038,50,121],
[2.2722,51,121],
[2.20829,52,121],
[2.14382,53,121],
[2.08824,54,121],
[2.02674,55,121],
[1.97253,56,121],
[1.9237,57,121],
[1.87045,58,121],
[1.81466,59,121],
[1.76943,60,121],
[1.71789,61,121],
[1.67441,62,121],
[1.62876,63,121],
[1.58121,64,121],
[1.54265,65,121],
[1.49515,66,121],
[1.45217,67,121],
[1.41226,68,121],
[1.37408,69,121],
[1.33772,70,121],
[1.30095,71,121],
[1.26747,72,121],
[1.23281,73,121],
[1.20393,74,121],
[1.17427,75,121],
[1.14722,76,121],
[1.12073,77,121],
[1.09651,78,121],
[1.0758,79,121],
[1.05595,80,121],
[1.03932,81,121],
[20.05,1,144],
[25.5408,2,144],
[27.2047,3,144],
[26.7454,4,144],
[25.8351,5,144],
[24.5634,6,144],
[23.1985,7,144],
[21.7284,8,144],
[20.4334,9,144],
[19.2432,10,144],
[18.1439,11,144],
[17.0151,12,144],
[16.0166,13,144],
[15.0825,14,144],
[14.2969,15,144],
[13.4895,16,144],
[12.7801,17,144],
[12.0962,18,144],
[11.5154,19,144],
[10.9742,20,144],
[10.3994,21,144],
[9.92663,22,144],
[9.44535,23,144],
[8.99111,24,144],
[8.62105,25,144],
[8.23679,26,144],
[7.88441,27,144],
[7.54128,28,144],
[7.24154,29,144],
[6.94393,30,144],
[6.65865,31,144],
[6.37952,32,144],
[6.13488,33,144],
[5.87829,34,144],
[5.66463,35,144],
[5.46318,36,144],
[5.23128,37,144],
[5.0601,38,144],
[4.86834,39,144],
[4.69606,40,144],
[4.52835,41,144],
[4.39421,42,144],
[4.23849,43,144],
[4.08307,44,144],
[3.94664,45,144],
[3.80985,46,144],
[3.69915,47,144],
[3.57408,48,144],
[3.47099,49,144],
[3.36192,50,144],
[3.26152,51,144],
[3.15566,52,144],
[3.063,53,144],
[2.98622,54,144],
[2.89284,55,144],
[2.81311,56,144],
[2.73397,57,144],
[2.66675,58,144],
[2.59584,59,144],
[2.52815,60,144],
[2.4677,61,144],
[2.40621,62,144],
[2.35021,63,144],
[2.29909,64,144],
[2.24701,65,144],
[2.19152,66,144],
[2.13839,67,144],
[2.09336,68,144],
[2.05383,69,144],
[2.00185,70,144],
[1.95541,71,144],
[1.91481,72,144],
[1.86782,73,144],
[1.83383,74,144],
[1.78649,75,144],
[1.74485,76,144],
[1.70457,77,144],
[1.66508,78,144],
[1.62887,79,144],
[1.59062,80,144],
[1.54997,81,144],
[1.51873,82,144],
[1.48138,83,144],
[1.4403,84,144],
[1.40909,85,144],
[1.37805,86,144],
[1.3449,87,144],
[1.30951,88,144],
[1.2823,89,144],
[1.25191,90,144],
[1.22702,91,144],
[1.19986,92,144],
[1.17344,93,144],
[1.15171,94,144],
[1.12705,95,144],
[1.10922,96,144],
[1.08884,97,144],
[1.07016,98,144],
[1.05446,99,144],
[1.03897,100,144],
[23.5656,1,169],
[30.6606,2,169],
[32.65,3,169],
[32.7604,4,169],
[31.7581,5,169],
[30.5051,6,169],
[28.8713,7,169],
[27.4496,8,169],
[25.7778,9,169],
[24.4418,10,169],
[23.0346,11,169],
[21.6902,12,169],
[20.6506,13,169],
[19.5046,14,169],
[18.5455,15,169],
[17.6191,16,169],
[16.7176,17,169],
[15.9602,18,169],
[15.1411,19,169],
[14.5163,20,169],
[13.8224,21,169],
[13.1697,22,169],
[12.5721,23,169],
[12.0804,24,169],
[11.5586,25,169],
[11.0872,26,169],
[10.614,27,169],
[10.2271,28,169],
[9.79856,29,169],
[9.43923,30,169],
[9.08202,31,169],
[8.7404,32,169],
[8.37218,33,169],
[8.08342,34,169],
[7.80064,35,169],
[7.52105,36,169],
[7.25939,37,169],
[7.02256,38,169],
[6.78287,39,169],
[6.55768,40,169],
[6.30288,41,169],
[6.12954,42,169],
[5.92392,43,169],
[5.75309,44,169],
[5.5541,45,169],
[5.37442,46,169],
[5.22356,47,169],
[5.05344,48,169],
[4.89452,49,169],
[4.76239,50,169],
[4.61445,51,169],
[4.47762,52,169],
[4.34455,53,169],
[4.23018,54,169],
[4.11035,55,169],
[3.9896,56,169],
[3.8792,57,169],
[3.76531,58,169],
[3.65873,59,169],
[3.56371,60,169],
[3.47164,61,169],
[3.375,62,169],
[3.28967,63,169],
[3.21151,64,169],
[3.12868,65,169],
[3.06161,66,169],
[2.97454,67,169],
[2.91112,68,169],
[2.83946,69,169],
[2.78127,70,169],
[2.70977,71,169],
[2.65318,72,169],
[2.59424,73,169],
[2.53568,74,169],
[2.48628,75,169],
[2.4347,76,169],
[2.38283,77,169],
[2.33865,78,169],
[2.29825,79,169],
[2.25089,80,169],
[2.20503,81,169],
[2.17168,82,169],
[2.12343,83,169],
[2.08615,84,169],
[2.04756,85,169],
[2.0104,86,169],
[1.97363,87,169],
[1.93899,88,169],
[1.89743,89,169],
[1.86274,90,169],
[1.82913,91,169],
[1.79172,92,169],
[1.76236,93,169],
[1.72591,94,169],
[1.68758,95,169],
[1.65392,96,169],
[1.62396,97,169],
[1.59183,98,169],
[1.55568,99,169],
[1.52609,100,169],
[1.49228,101,169],
[1.46285,102,169],
[1.43692,103,169],
[1.40301,104,169],
[1.376,105,169],
[1.34595,106,169],
[1.31864,107,169],
[1.28992,108,169],
[1.26516,109,169],
[1.24,110,169],
[1.21826,111,169],
[1.19292,112,169],
[1.17477,113,169],
[1.15484,114,169],
[1.13299,115,169],
[1.11776,116,169],
[1.10012,117,169],
[1.08149,118,169],
[1.06682,119,169],
[1.05268,120,169],
[1.03929,121,169]
]
xgrid, ygrid = np.meshgrid(X, Y)
zgrid = np.zeros([len(Y), len(X)])
for i in range(len(Z)):
    zgrid[Y.index(Z[i][1])][X.index(Z[i][2])] = Z[i][0]

fig = pylab.figure()
axes = Axes3D(fig)
axes.plot_surface(xgrid, ygrid, zgrid, rstride=1, cstride=1, cmap=cm.jet)
pylab.show()

