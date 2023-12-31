import sys

out_filename = 'iocBoot/iocBS_EM/calibration.ini';
in_filename = 'dbpm_calibration.ini';
calibration_name = sys.argv[1];

STATE_COPY=1;
STATE_IGNORE=0;

out_file = open(out_filename, 'w');
in_file = open(in_filename, 'r');

found_cal = 0; # Boolean indicating if a calibration line was found

cal_state = STATE_IGNORE;       # Start out not copying lines
find_string = '[{}_range'.format(calibration_name); # Get pattern
for curr_line in in_file:
    strip_line = curr_line.strip();
    out_line = '\n';            # Start with a benign line
    if cal_state == STATE_IGNORE:
        if strip_line.startswith(find_string):
            found_cal = 1; # Note we have found a line.  Assume the calibration is valid.
            cal_state = STATE_COPY; # Note that we will copy lines now
            split_line = strip_line.split('_',1); # Separate name from param
            split_line[0] = '[direct';            # Rewrite with used name
            out_line ='_'.join(split_line);      # Reassemble
            out_line = out_line+'\n';             # Append newline
    else:                                     # Copying a line
        if strip_line.startswith('[') and (not strip_line.startswith(find_string)):
            cal_state = STATE_IGNORE;
        elif strip_line.startswith(find_string):
            split_line = strip_line.split('_',1); # Separate name from param
            split_line[0] = '[direct';
            out_line = '_'.join(split_line);
            out_line = out_line+'\n';
        else:
            out_line = curr_line;

    if cal_state == STATE_COPY:
        out_file.write(out_line);


exit_code = 0;                  # Set a default exit code
if found_cal != 0:              # XXX Found at least one line
    out_file.write("Name:{}\n".format(calibration_name)); # Note the actual name for EPICS
    exit_code = 0;                # Assume good and return success
else:                           # No lines found
    exit_code = 1;              # Report failure
    
out_file.close();
in_file.close();                # Close the files


cal_name_filename = 'iocBoot/iocBS_EM/calname.cmd';

cal_name_file = open(cal_name_filename, "w");
cal_name_file.write("dbpf $(PREFIX)$(RECORD)CalName_RBV \"{}\"\n".format(calibration_name))
cal_name_file.close();

sys.exit(exit_code);            # Report the exit status
