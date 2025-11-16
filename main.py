import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

sns.set_theme(style="whitegrid", font_scale=1.2)

def plot_data(csv_file, title, output_png):
    df = pd.read_csv(csv_file)

    df_long = df.melt(
        id_vars="n",
        var_name="algorithm",
        value_name="time"
    )

    plt.figure(figsize=(14, 8))
    sns.lineplot(
        data=df_long,
        x="n",
        y="time",
        hue="algorithm",
        marker=""
    )

    plt.title(title)
    plt.xlabel("Размер массива n")
    plt.ylabel("Время (млс)")
    plt.legend(title="Алгоритм", loc="upper left")
    plt.ylim(0, 15)
    plt.xlim(left=0)

    plt.tight_layout()
    plt.savefig(output_png)
    plt.show()


plot_data("random.csv",
          title="случайные массивы",
          output_png="random_plot.png")

plot_data("reverse.csv",
          title="обратно отсортированные массивы",
          output_png="reverse_plot.png")

plot_data("almost_sorted.csv",
          title="почти отсортированные массивы",
          output_png="almost_sorted_plot.png")