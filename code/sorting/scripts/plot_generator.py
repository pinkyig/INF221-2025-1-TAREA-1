import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('../data/measurements/time.txt')


# Filtrar los datos de tipo 'aleatorio'
df_aleatorio = df[df['type'] == 'aleatorio']

# Graficar el tamaño de la entrada con respecto al tiempo para cada algoritmo
plt.figure(figsize=(10, 6))
plt.plot(df_aleatorio['size'], df_aleatorio['MergeSort_microseg'], label='MergeSort')
plt.plot(df_aleatorio['size'], df_aleatorio['QuickSort_microseg'], label='QuickSort')
plt.plot(df_aleatorio['size'], df_aleatorio['SelectionSort_microseg'], label='SelectionSort')
plt.plot(df_aleatorio['size'], df_aleatorio['LibrarySort_microseg'], label='LibrarySort')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la entrada')
plt.ylabel('Tiempo (microsegundos)')
plt.title('Tamaño de la entrada vs Tiempo para datos aleatorios')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.savefig('../data/plots/aleatorio_plot.png')  # Guardar gráfico
plt.close()

# Filtrar los datos de tipo 'ascendente'
df_ascendente = df[df['type'] == 'ascendente']

# Graficar el tamaño de la entrada con respecto al tiempo para cada algoritmo
plt.figure(figsize=(10, 6))
plt.plot(df_ascendente['size'], df_ascendente['MergeSort_microseg'], label='MergeSort')
plt.plot(df_ascendente['size'], df_ascendente['QuickSort_microseg'], label='QuickSort')
plt.plot(df_ascendente['size'], df_ascendente['SelectionSort_microseg'], label='SelectionSort')
plt.plot(df_ascendente['size'], df_ascendente['LibrarySort_microseg'], label='LibrarySort')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la entrada')
plt.ylabel('Tiempo (microsegundos)')
plt.title('Tamaño de la entrada vs Tiempo para datos ascendentes')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.savefig('../data/plots/ascendente_plot.png')  # Guardar gráfico
plt.close()

# Filtrar los datos de tipo 'descendente'
df_descendente = df[df['type'] == 'descendente']

# Graficar el tamaño de la entrada con respecto al tiempo para cada algoritmo
plt.figure(figsize=(10, 6))
plt.plot(df_descendente['size'], df_descendente['MergeSort_microseg'], label='MergeSort')
plt.plot(df_descendente['size'], df_descendente['QuickSort_microseg'], label='QuickSort')
plt.plot(df_descendente['size'], df_descendente['SelectionSort_microseg'], label='SelectionSort')
plt.plot(df_descendente['size'], df_descendente['LibrarySort_microseg'], label='LibrarySort')

# Configurar etiquetas y título
plt.xlabel('Tamaño de la entrada')
plt.ylabel('Tiempo (microsegundos)')
plt.title('Tamaño de la entrada vs Tiempo para datos descendentes')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.savefig('../data/plots/descendente_plot.png')  # Guardar gráfico
plt.close()