import sys

pv_list_filename = sys.argv[1]; # Filename holding the PVs to put in big flnk
flnk_filename = sys.argv[2];    # Filename to output the database

pv_list_file = open(pv_list_filename, "r");
flnk_file = open(flnk_filename, "w"); # Open the files

fanout_record_count = 0;
pv_record_count = 1;

for curr_line in pv_list_file:
    stripped_line = curr_line.strip();
    if (stripped_line == ""):
        continue;
    flnk_file.write('field(LNK{}, "{}.PROC")\n'.format(pv_record_count, stripped_line));
    pv_record_count = (pv_record_count + 1) % 5;
    if pv_record_count == 0:
        pv_record_count = 1;

flnk_file.close();
pv_list_file.close();
