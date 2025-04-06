import psutil
import time
import matplotlib.pyplot as plt

# Function to monitor CPU usage (representative of server load)
def monitor_cpu_usage():
    cpu_usage = psutil.cpu_percent(interval=1)
    return cpu_usage

# Function to log performance data
def log_performance():
    cpu_usages = []
    times = []
    start_time = time.time()

    # Monitor for 10 seconds
    for i in range(10):
        cpu_usage = monitor_cpu_usage()
        cpu_usages.append(cpu_usage)
        times.append(i + 1)
        time.sleep(1)

    # Plot the CPU usage over time
    plt.plot(times, cpu_usages)
    plt.xlabel("Time (s)")
    plt.ylabel("CPU Usage (%)")
    plt.title("CPU Usage Over Time")
    plt.show()

if __name__ == "__main__":
    log_performance()