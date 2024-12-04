# run lizard on the two files
# compare metrics for each of the files
# doesn't look at actual complexity of the code, only how complex it looks
# NLOC - number of non-commentating lines of code (ignores comments and blanks)
# CCN - cyclomatic complexity number --> number of linearly independent paths (decision points)
# token count of functions --> number of variables, keywords, operators, etc
# parameter count of functions --> number of parameters in each function

# !/bin/bash
output_dir="lizard_outputs"
mkdir -p "$output_dir"

for file in "$1" "$2" "$3"; do

  # Extract the filename without the extension
  filename=$(basename "$file" .c)

  # Run lizard and save the output to a file named after the input file
  lizard "$file" > "${output_dir}/${filename}_lizard_report.txt"

  echo "Lizard analysis for '$file' saved to '${filename}_lizard_report.txt'."
done