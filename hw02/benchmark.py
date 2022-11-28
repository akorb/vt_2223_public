import os
import subprocess
from itertools import product

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

CSV_FILE = 'times.csv'

matplotlib.use('Agg')


class Scenario:
    def __init__(self, probs, seed, code_size):
        self.probs = probs
        self.seed = seed
        self.code_size = code_size

    def to_str_list(self):
        l = self.probs + [self.seed, self.code_size]
        l_str = list(map(str, l))
        return l_str


scenarios = {1: Scenario(probs=[0, 1, 0, 0, 0], seed=1, code_size=10000),
             2: Scenario(probs=[1, 1, 1, 0, 0], seed=1, code_size=10000),
             3: Scenario(probs=[1, 9, 1, 5, 5], seed=1, code_size=10000),
             4: Scenario(probs=[1, 9, 1, 5, 5], seed=1, code_size=50000)}

implementations = ['simple', 'super_events', 'indirect_threaded', 'direct_threaded']


def time_scenario(num, implementation):
    p = subprocess.run([f'cmake-build-release/{implementation}'] + scenarios[num].to_str_list(), capture_output=True)
    time = float(p.stdout)
    return time


def main():
    if not os.path.isfile(CSV_FILE):
        output_file = open(CSV_FILE, 'w')
        output_file.write('scenario_num,implementation,time\n')
        for scenario_num, impl in product(scenarios.keys(), implementations):
            for _ in range(1000):
                time = time_scenario(scenario_num, implementation=impl)
                output_file.write(f"{scenario_num},{impl},{time}\n")

        output_file.close()
    else:
        print(f'Use existing {CSV_FILE}')

    df = pd.read_csv(CSV_FILE)
    df.sort_values(by='scenario_num', inplace=True)

    x = np.arange(len(scenarios))  # the label locations
    width = 0.2  # the width of the bars

    fig, ax = plt.subplots()

    n = len(implementations)
    for i, impl in enumerate(implementations):
        impl_df = df[df['implementation'] == impl]
        means = impl_df.groupby('scenario_num')['time'].mean()
        ax.bar(x + (-((n - 1) / 2) * width + i * width), means, width, label=impl, log=True)
    ax.set_xticks(x, scenarios.keys())
    ax.legend()

    plt.xlabel('Scenario')
    plt.ylabel('Duration [ms]')

    plt.savefig('benchmark.png')


if __name__ == "__main__":
    main()
