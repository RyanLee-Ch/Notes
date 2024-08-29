# This code was created by Ryan Lee (李英杰) and is for work use only.
# For usage requests, please email: ryanlee990929@gmail.com
# Or number: +86 18277135262

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用黑体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 初始条件
x_values = np.arange(0, 4.5 + 0.001, 0.001)  # 位置从0到4.5米，步进0.001米
v_container = 0  # 初始速度
g = 9.81  # 重力加速度，m/s^2
m = 30.0  # 容器质量，kg
mg = m * g  # 重力，N
p_1 = 101325  # 初始压力，Pa
h_pipe = 4.5  # 管道高度，m
d_pipe = 0.3  # 管道直径，m
d_container = 0.295  # 容器直径，m
h_container = 0.4  # 容器高度，m
gamma = 1.4
eta = 1.81e-5  # 空气动力粘度，Pa.s
C_d = 1.0
rho = 1.225  # 空气密度，kg/m^3
k = 64
A_container = np.pi * (d_container / 2) ** 2  # 容器截面积

results = []

for x in x_values:
    # 计算空气缓冲效应力
    air_cushion_effect = (p_1 * A_container * ((h_pipe / (h_pipe - x)) ** gamma - 1)) / ((d_pipe / d_container) ** k)
    
    # 计算空气阻力
    air_drag = 0.5 * C_d * rho * A_container * v_container**2
    
    # 计算黏性摩擦力
    viscous_friction = -2 * np.pi * v_container * eta * (d_container * h_container) / (d_pipe - d_container)
    
    # 计算净力（重力减去所有其他力）
    net_force = mg - (air_cushion_effect + air_drag + viscous_friction)
    
    # 计算加速度
    acceleration = net_force / m
    
    # 检查加速度是否为负数
    if acceleration < 0:
        print("加速度在位置", x, "时为负数，停止计算。")
        break
    
    # 更新速度 (v = u + at, 这里 u = v_container)
    v_container += acceleration * 0.001  # 假设小时间间隔对应于位置步长
    
    # 存储每一步的结果
    results.append([x, v_container, acceleration, mg, air_cushion_effect, (d_pipe / d_container) ** k, air_drag, viscous_friction, net_force])

# 将结果转换为numpy数组以便更方便处理
results_array = np.array(results)

# 创建DataFrame以显示结果
columns = ["位置 (m)", "速度 (m/s)", "加速度 (m/s^2)", "重力 (N)", 
           "空气缓冲效应力 (N)", "修正因子", "空气阻力 (N)", "黏性摩擦力 (N)", "净力 (N)"]
results_df = pd.DataFrame(results_array, columns=columns)

# 将DataFrame保存到CSV文件
results_df.to_csv('container_motion_state.csv', index=False)

print("结果已保存到 'container_motion_state.csv'。")

# 绘图
plt.figure(figsize=(10, 8))

# 创建双 Y 轴图
ax1 = plt.subplot(2, 1, 1)

# 速度图（左侧Y轴）
ax1.set_xlabel('位置 (m)')
ax1.set_ylabel('速度 (m/s)', color='b')
ax1.plot(results_df["位置 (m)"], results_df["速度 (m/s)"], label='速度 (m/s)', color='b')
ax1.tick_params(axis='y', labelcolor='b')

# 加速度图（右侧Y轴）
ax2 = ax1.twinx()
ax2.set_ylabel('加速度 (m/s^2)', color='r')
ax2.plot(results_df["位置 (m)"], results_df["加速度 (m/s^2)"], label='加速度 (m/s^2)', color='r')
ax2.tick_params(axis='y', labelcolor='r')

# 图表标题和网格
ax1.set_title('速度与加速度随位置的变化')
ax1.grid(True)

# 在速度和加速度图中标注6个阶段
stages = [0, len(results_df) // 5, 2 * len(results_df) // 5, 3 * len(results_df) // 5, 4 * len(results_df) // 5, len(results_df) - 1]
for i in stages:
    x = results_df.iloc[i]["位置 (m)"]
    v = results_df.iloc[i]["速度 (m/s)"]
    a = results_df.iloc[i]["加速度 (m/s^2)"]
    ax1.text(x, v, f'{v:.2f}', color='b', ha='right')
    ax2.text(x, a, f'{a:.2f}', color='r', ha='left')

# 净力图在下面
ax3 = plt.subplot(2, 1, 2)
ax3.plot(results_df["位置 (m)"], results_df["净力 (N)"], label='净力 (N)', color='green')
ax3.set_xlabel('位置 (m)')
ax3.set_ylabel('净力 (N)')
ax3.set_title('净力随位置的变化')
ax3.grid(True)

# 在净力图中标注6个阶段
for i in stages:
    x = results_df.iloc[i]["位置 (m)"]
    f = results_df.iloc[i]["净力 (N)"]
    ax3.text(x, f, f'{f:.2f}', color='green', ha='right')

plt.tight_layout()
plt.show()
