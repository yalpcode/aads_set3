import math
import subprocess
import numpy as np
import matplotlib.pyplot as plt

S = 0.25 * math.pi + 1.25 * math.asin(0.8) - 1

S_ws = []
S_ns = []
S_rel_ws = []
S_rel_ns = []

def run_ai1(N, flag):
    cmd = f'./Ai1 {N} {flag} < input.txt'
    result = subprocess.run(
        cmd,
        shell=True,
        capture_output=True,
        text=True,
        check=True,
    )
    out = result.stdout.strip().split()
    return float(out[0])

Ns = np.arange(100, 100001, 500)

for N in Ns:
    S_w = run_ai1(N, flag=0)
    S_ws.append(S_w)
    S_rel_ws.append(abs(S_w - S) / S)

    S_n = run_ai1(N, flag=1)
    S_ns.append(S_n)
    S_rel_ns.append(abs(S_n - S) / S)

S_ws = np.array(S_ws)
S_ns = np.array(S_ns)
S_rel_ws = np.array(S_rel_ws)
S_rel_ns = np.array(S_rel_ns)

plt.figure(figsize=(10, 6))
plt.plot(Ns, S_ws, label="Широкий прямоугольник", color='#8DD3C7')
plt.plot(Ns, S_ns, label="Узкий прямоугольник", color='#FB8072')
plt.axhline(S, linestyle="--", label="Точное значение S", alpha=0.9, color='#BC80BD')
plt.xlabel("Количество точек N")
plt.ylabel("Оценка площади пересечения")
plt.title("Приближeнное значение площади пересечения трeх окружностей")
plt.ylim(S - 0.05, S + 0.05)
plt.legend()
plt.tight_layout()
plt.savefig('S.png')

plt.figure(figsize=(10, 6))
plt.plot(Ns, S_rel_ws, label="Широкий прямоугольник", color='#8DD3C7')
plt.plot(Ns, S_rel_ns, label="Узкий прямоугольник", color='#FB8072')
plt.xlabel("Количество точек N")
plt.ylabel("Относительное отклонение $\\frac{|S_{получ} - S_{ист}|}{S_{ист}}$")
plt.title("Относительное отклонение оценки площади от точного значения")
plt.legend()
plt.tight_layout()
plt.savefig('S_rel.png')