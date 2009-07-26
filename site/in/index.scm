(h2 "DESCRIPTION")
(p "Filter Chains Processor (FCP) is a command line utility that "
   "handles multiple files transformations, automatically building filter "
   "chains in order to transform each input file from its format to the "
   "desired output format.")
(p "Each filter chain is computed dinamically, using external tools (defined "
   "by the user in a configuration file).")

(h2 "USAGE")
(pre (@ class "terminal")
"Usage: fcp [OPTION]... [TRANSFORMATION]...

Options:
  -r, --rules=FILE	  use alternate rules file
			  [default $HOME/.fcp/rules]
  -m, --max-depth=NUM	  use NUM as max filter-chains depth
			  [default 16]
  -t, --temp-dir=DIR	  use DIR as temporary directory
			  [default $HOME/.fcp/tmp]
  -s, --separator=CHAR	  use CHAR as INPUTFILE/OUTPUTFILE separator
			  [default `:']
  -q, --no-std-rules	  do not load standard rules
  -b, --dump-rules	  dump rules base, then exit
  -n, --dry-run		  display commands without modifying any files
  -f, --force             consider all files out of date
  -d, --debug		  enable debugging traces
  -v, --verbose		  verbosely report processing
  -h, --help		  print this help, then exit
  -V, --version		  print version number, then exit
")

(p "Although some (maybe) sane default values are hardwired into the "
   "program, the following options allow overriding:")

(ul
 (li (kbd "-r") ", " (kbd "--rules") ": "
     "Specify a different rules file. "
     "This option could be specified multiple times.")

 (li (kbd "-m") ", " (kbd "--max-depth") ": "
     "Specify maximum filter chains length")

 (li (kbd "-r") ", " (kbd "--temp-dir") ": "
     "Specify a temporary directory")

 (li (kbd "-s") ", " (kbd "--separator") ": "
     "Overrides transformation separator")

 (li (kbd "-q") ", " (kbd "--no-std-rules") ": "
     "Do not load default rules file, starting with an empty rules-base")

 (li (kbd "-b") ", " (kbd "--dump-rules") ": "
     "Start the program, dump the rules-base then exit. "
     "Useful for debugging your rules-base (and the program itself)")

 (li (kbd "-f") ", " (kbd "--force") ": "
     "Run the program without regenerating updated files")

 (li (kbd "-n") ", " (kbd "--dry-run") ": "
     "Run the program without modifyng any files")
 )

(h3 "Rules file format")
(p "Input rules files use a stripped-down grammar which resembles Makefile's "
   "grammar. Input files contain: directives, comments and rules.")

(h5 "Directives")
(p "A \"directive\" is a command for `fcp' to do something special while "
   "reading the rules file. These include:")
(ul
 (li "Reading another rules file")

 (li "Deciding (based on the values of variables) whether to use or "
     "ignore a part of the file [" (i "NOT YET IMPLEMENTED") "]")
 )

(h5 "Comments")
(p "`#' in a line of a rules file starts a \"comment\". It and the rest "
   "of the line are ignored, except that a trailing backslash not "
   "escaped by another backslash will continue the comment across "
   "multiple lines.  A line containing just a comment (with perhaps "
   "spaces before it) is effectively blank, and is ignored.")
(p "If you want a literal `#', escape it with a backslash (e.g., `\\#').")
(p "Comments may appear on any line in the rules file, although they are "
   "treated specially in certain situations")

(h5 "Rules")
(p "A rule says how to build one or more files, called the rule's "
   "targets. A rule has the following format:")
(pre (@ class "terminal")
"<INPUT_EXTENSION>:<OUTPUT_EXTENSION>:
         <COMMAND> [PARAMETERS]...
         <COMMAND> [PARAMETERS]...
")

(p "The following special variables are available inside each target commands:")
(ul
 (li (kbd "$I") ": The transformation input file name")
 (li (kbd "$O") ": The transformation output file name")
 (li (kbd "$T[0-9]+") ": A temporary filename")
 )

(h3 "Examples")
(h5 "Dumping the actual rules-base")
(pre (@ class "terminal") "$ fcp -b")

(h2 "COPYING")
(p "FCP is licensed under the "
   (a (@ (href "http://www.gnu.org/licenses/licenses.html"))
      "GNU General Public License, version 2"))

(h2 "MAINTAINERS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h2 "AUTHORS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h2 "MAILING LISTS")
(p "The project has a single moderated mailing list, with an archive. "
   "In order to post a message to the mailing list you must be subscribed. "
   "Please consult the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/fcproc-generic"))
      "mailing list page")
   " for more information on subscribing to the mailing list.")

(h2 "REPORT A BUG")
(p "If you think you have found a bug then please send as complete a report "
   "as possible to "
   "<fcproc-generic AT nongnu DOT org>. "
   "An easy way to collect all the required information, such as platform and "
   "compiler, is to include in your report the config.log file available at "
   "the end of the configuration procedure.")
(p "If you have a patch for a bug that hasn't yet been fixed in "
   "the latest repository sources, please be so kind to create it using the "
   "repository sources, not the release sources.")
