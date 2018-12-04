size = int(input("Enter Number of Processes"))
quantum = int(input("Enter Time Quantum : "))
time = 0

burst_time = [0] * int(size)
remaining_burst_time = [0] * int(size)
arrival_time = [0] * int(size)
process_id = [0] * int(size)
waiting_time = [0] * int(size)
turnaround_time = [0] * int(size)
final_time=[0] * size

for i in range(int(size)):
    print(" ")
    process_id[i] = input("Enter Process_Id")
    arrival_time[i] = input("Enter Arrival_Time")
    burst_time[i] = input("Enter Burst_Time")

for i in range(int(size)):

    for j in range(int(size) - 1):

        if arrival_time[j] > arrival_time[j + 1]:
            arrival_time[j], arrival_time[j + 1] = arrival_time[j + 1], arrival_time[j]
            process_id[j], process_id[j + 1] = process_id[j + 1], process_id[j]
            burst_time[j], burst_time[j + 1] = burst_time[j + 1], burst_time[j]

for i in range(int(size)):
    remaining_burst_time[i] = int(burst_time[i])
k = 1
while k>0:

    l = 0

    for i in range(size):

        if int(remaining_burst_time[i]) > 0:

            l = 1

            if remaining_burst_time[i] > int(quantum):

                time += quantum
                remaining_burst_time[i] -= quantum

            elif remaining_burst_time[i] <= quantum:

                time += remaining_burst_time[i]
                waiting_time[i] = time - int(burst_time[i])
                remaining_burst_time[i] = 0

    if l == 0:
        break

for i in range(size):
    turnaround_time[i] = int(burst_time[i]) + waiting_time[i]

print(" ")
print("Process_Id    Arrival_Time    Burst_Time    Turnaround_Time    Waiting_Time")
print(" ")

for i in range(size):
    print("    ", process_id[i], "          ", arrival_time[i], "             ", burst_time[i], "              ",
          turnaround_time[i]+1, "             ", waiting_time[i]+1)

total = 0
for i in range(size):
    total += turnaround_time[i]

