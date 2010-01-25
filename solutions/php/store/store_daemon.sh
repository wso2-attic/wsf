#!/bin/bash
#

START_VAL=25
MIN_COUNT=20

echo ""
echo "===========|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|==========="
echo "||                                                      ||"
echo "||                                                      ||"
echo "============= RAMPART BACKPACK MANUFACTURERS ============="
echo "||                                                      ||"
echo "||                                                      ||"
echo "=========================================================="
echo ""
echo -n "Stock available = "

while (( START_VAL >= MIN_COUNT ))
do
    if (( START_VAL<10 )); then
    echo -n "$START_VAL "
    else
    echo -n "$START_VAL"
    fi

    (( START_VAL-- ))
    sleep 1

    echo -n -e \\b\\b
done

echo "WARNING: Stock goes down below $MIN_COUNT ... Placing a new order"
echo ""
echo ""
sleep 2
php store_client.php
echo ""
echo ""
echo ""
echo ""
echo "Deamon is sleeping!"

