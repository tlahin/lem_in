MAP_DIR=./tests



if [ ! -d "$MAP_DIR" ]
then
	mkdir "$MAP_DIR"
else
	rm -rf "$MAP_DIR"
	mkdir "$MAP_DIR"
fi

if [ test_results ]
then
	rm test_results
fi

for i in {1..10}
do
	"./generator" --big-superposition > "$MAP_DIR/map_$i"
	sleep 1
done

for i in {1..10}
do
	printf "$MAP_DIR/map_$i" | rev | cut -d '/' -f 1 | rev >> test_results
	head -n 2 "$MAP_DIR/map_$i"  | grep "required" | cut -d : -f2 >> test_results
	time ../lem-in -q -l < "$MAP_DIR/map_$i" >> test_results
	printf "\n\n___________________________________________________\n" >> test_results
done
