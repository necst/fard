#times_end_broadcast_1 = [line.rstrip('\n') for line in open("times_end_broadcast_1.txt")]
#times_start_broadcast_1 = [line.rstrip('\n') for line in open("times_start_broadcast_1.txt")]

#times_end_unicast_1 = [line.rstrip('\n') for line in open("times_end_unicast_1.txt")]
#times_start_unicast_1 = [line.rstrip('\n') for line in open("times_start_unicast_1.txt")]

#times_end_multicast_1 = [line.rstrip('\n') for line in open("times_end_multicast_1.txt")]
#times_start_multicast_1 = [line.rstrip('\n') for line in open("times_start_multicast_1.txt")]

import ast
import statistics
import os.path

times_end_broadcast_25 = [ast.literal_eval(line.rstrip('\n')) for line in open("times_end_unicast_182.txt")]
times_start_broadcast_25 = [ast.literal_eval(line.rstrip('\n')) for line in open("times_start_unicast_182.txt")]

times_broadcast_25 = []
list_time = []
sum_time_1 = 0
sum_time_2 = 0

for entry_end in times_end_broadcast_25:
    for entry_start in times_start_broadcast_25:
        if entry_start["Run"] == entry_end["Run"] and entry_start["It"] == entry_end["It"]:
            times_broadcast_25.append({"Time": entry_end["Time"] - entry_start["Time"], "Run": entry_end["Run"], "It": entry_end["It"]})

for entry in times_broadcast_25:
    sum_time_1 = sum_time_1 + entry["Time"]
    list_time.append(entry["Time"])

median = statistics.median(list_time)
mean = statistics.mean(list_time)
stdev = statistics.stdev(list_time)

if(os.path.isfile("unicast_times.txt") == False):
    with open("unicast_times.txt", "w+") as f:
        f.write("It\tMean\tMedian\tStdev\n")

with open("unicast_times.txt", "a") as f:
    f.write("182\t"+ str(mean)+ "\t" + str(median) + "\t" + str(stdev) + "\n")
