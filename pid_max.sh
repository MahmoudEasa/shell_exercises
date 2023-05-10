#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "The maximum value for a process ID is: $pid_max"

