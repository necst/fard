#times_end_broadcast_1 = [line.rstrip('\n') for line in open("times_end_broadcast_1.txt")]
#times_start_broadcast_1 = [line.rstrip('\n') for line in open("times_start_broadcast_1.txt")]

#times_end_unicast_1 = [line.rstrip('\n') for line in open("times_end_unicast_1.txt")]
#times_start_unicast_1 = [line.rstrip('\n') for line in open("times_start_unicast_1.txt")]

#times_end_multicast_1 = [line.rstrip('\n') for line in open("times_end_multicast_1.txt")]
#times_start_multicast_1 = [line.rstrip('\n') for line in open("times_start_multicast_1.txt")]

import ast
import statistics
import os.path

times_end_broadcast_25 = [ast.literal_eval(line.rstrip('\n')) for line in open("times_end_multicast_182.txt")]
times_start_broadcast_25 = [ast.literal_eval(line.rstrip('\n')) for line in open("times_start_multicast_182.txt")]

senders = []
times_end_broadcast_25_1 = []
times_end_broadcast_25_2 = []
times_broadcast_25_1 = []
times_broadcast_25_2 = []
list_time_1 = []
list_time_2 = []
sum_time_1 = 0
sum_time_2 = 0

for entry in times_end_broadcast_25:
    if entry["Sender"] not in senders:
        senders.append(entry["Sender"])

for entry in times_end_broadcast_25:
    if entry["Sender"] == senders[0]:
        times_end_broadcast_25_1.append(entry)
    else:
        times_end_broadcast_25_2.append(entry)

for entry_end in times_end_broadcast_25_1:
    for entry_start in times_start_broadcast_25:
        if entry_start["Run"] == entry_end["Run"] and entry_start["It"] == entry_end["It"]:
            times_broadcast_25_1.append({"Time": entry_end["Time"] - entry_start["Time"], "Run": entry_end["Run"], "It": entry_end["It"], "Sender": entry_end["Sender"]})

for entry_end in times_end_broadcast_25_2:
    for entry_start in times_start_broadcast_25:
        if entry_start["Run"] == entry_end["Run"] and entry_start["It"] == entry_end["It"]:
            times_broadcast_25_2.append({"Time": entry_end["Time"] - entry_start["Time"], "Run": entry_end["Run"], "It": entry_end["It"], "Sender": entry_end["Sender"]})

for entry in times_broadcast_25_1:
    sum_time_1 = sum_time_1 + entry["Time"]
    list_time_1.append(entry["Time"])

for entry in times_broadcast_25_2:
    sum_time_2 = sum_time_2 + entry["Time"]
    list_time_2.append(entry["Time"])

median_1 = statistics.median(list_time_1)
median_2 = statistics.median(list_time_2)

mean_1 = statistics.mean(list_time_1)
mean_2 = statistics.mean(list_time_2)

stdev_1 = statistics.stdev(list_time_1)
stdev_2 = statistics.stdev(list_time_2)

list_time = list_time_1 + list_time_2

median = statistics.median(list_time)
mean = statistics.mean(list_time)
stdev = statistics.stdev(list_time)

if(os.path.isfile("multicast_times.txt") == False):
    with open("multicast_times.txt", "w+") as f:
        f.write("It\tMean\tMedian\tStdev\n")

with open("multicast_times.txt", "a") as f:
    f.write("182\t"+ str(mean)+ "\t" + str(median) + "\t" + str(stdev) + "\n")
