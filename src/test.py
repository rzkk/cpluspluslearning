'''
Author: rzk ruanzk2098@gmial.com
Date: 2025-01-16 11:55:58
LastEditors: rzk ruanzk2098@gmial.com
LastEditTime: 2025-01-16 11:56:02
FilePath: /cplusplus/src/test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import matplotlib.pyplot as plt

# 创建网格
x = np.linspace(-1.5, 1.5, 400)
y = np.linspace(-1.5, 1.5, 400)
X, Y = np.meshgrid(x, y)

# 方程 5 * x^2 * y^2 + y^4 = 1
Z = 5 * X**2 * Y**2 + Y**4 - 1

# 绘制等高线图
plt.contour(X, Y, Z, levels=[0], colors='b')
plt.xlabel('x')
plt.ylabel('y')
plt.title(r'$5x^2y^2 + y^4 = 1$')
plt.grid(True)
plt.axhline(0, color='black',linewidth=1)
plt.axvline(0, color='black',linewidth=1)
plt.show()