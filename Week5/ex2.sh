while true; do
    if (( ! ln ex2.txt ))
    then
       sleep 1
    else
        if [ ! -f ex2.txt ]; then echo 0 > ex2.txt; fi
        count=0
        while [[ $count != 100 ]]; do
            count=`expr $count + 1`
            n=`tail -1 ex2.txt`
            expr $n + 1 >> ex2.txt
        done
        break
    fi
done 
