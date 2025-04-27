import pandas as pd
import matplotlib.pyplot as plt

# Cargar datos
datos = pd.read_csv('code/matrix_multiplication/data/measurements/time.txt')

# Valores específicos para el eje x
x_ticks = [16, 256, 512, 1024]

# Filtrar matrices densas
matrices_densas = datos[(datos['typeA'] == 'densa') & (datos['typeB'] == 'densa')]

plt.figure(figsize=(10, 6))

# Graficar tiempo de ejecución para el algoritmo naive
plt.plot(matrices_densas['sizeA'], matrices_densas['tiempo_naive_microseg'], label='Naive', marker='o')

# Graficar tiempo de ejecución para el algoritmo de Strassen
plt.plot(matrices_densas['sizeA'], matrices_densas['tiempo_strassen_microseg'], label='Strassen', marker='o')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la matriz (sizeA)')
plt.ylabel('Tiempo de ejecución (microsegundos)')
plt.title('Tamaño vs Tiempo de ejecución para matrices densas')
plt.legend()
plt.grid(True)

plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.xticks(x_ticks, x_ticks)  # Establecer marcas específicas en el eje x
plt.savefig('code/matrix_multiplication/data/plots/dense_matrices_plot.png')  # Guardar gráfico
plt.close()

# Filtrar matrices diagonales
matrices_diagonales = datos[(datos['typeA'] == 'diagonal') & (datos['typeB'] == 'diagonal')]

plt.figure(figsize=(10, 6))

# Graficar tiempo de ejecución para el algoritmo naive
plt.plot(matrices_diagonales['sizeA'], matrices_diagonales['tiempo_naive_microseg'], label='Naive', marker='o')

# Graficar tiempo de ejecución para el algoritmo de Strassen
plt.plot(matrices_diagonales['sizeA'], matrices_diagonales['tiempo_strassen_microseg'], label='Strassen', marker='o')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la matriz (sizeA)')
plt.ylabel('Tiempo de ejecución (microsegundos)')
plt.title('Tamaño vs Tiempo de ejecución para matrices diagonales')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.xticks(x_ticks, x_ticks)  # Establecer marcas específicas en el eje x
plt.savefig('code/matrix_multiplication/data/plots/diagonal_matrices_plot.png')  # Guardar gráfico
plt.close()

# Filtrar matrices dispersas
matrices_dispersas = datos[(datos['typeA'] == 'dispersa') & (datos['typeB'] == 'dispersa')]

plt.figure(figsize=(10, 6))

# Graficar tiempo de ejecución para el algoritmo naive
plt.plot(matrices_dispersas['sizeA'], matrices_dispersas['tiempo_naive_microseg'], label='Naive', marker='o')

# Graficar tiempo de ejecución para el algoritmo de Strassen
plt.plot(matrices_dispersas['sizeA'], matrices_dispersas['tiempo_strassen_microseg'], label='Strassen', marker='o')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la matriz (sizeA)')
plt.ylabel('Tiempo de ejecución (microsegundos)')
plt.title('Tamaño vs Tiempo de ejecución para matrices dispersas')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.xticks(x_ticks, x_ticks)  # Establecer marcas específicas en el eje x
plt.savefig('code/matrix_multiplication/data/plots/sparse_matrices_plot.png')  # Guardar gráfico
plt.close()
