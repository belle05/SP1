import subprocess
import glob
import os

tests = glob.glob("./tests/*.in")
tests.sort()
results = glob.glob("./results/*.out")
results.sort()

for index, test in enumerate(tests):
	print "\nGoing to try test number " + str(index+1) + "..."
	result_file = "result" + str(index+1) + ".out"
	bash_ex = "./ex1 < " + test + " > " + result_file
	os.system(bash_ex)
	bash_diff = "diff ./" + result_file + " " + results[index]
	output = subprocess.check_output(['bash','-c', bash_diff])
	if output!='':
		print "for " + test + " result is: " + str(output)
	else:
		print "Success!"
