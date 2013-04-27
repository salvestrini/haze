;;; File: emacs-format-file
;;; Stan Warford
;;; 17 May 2006

(defun emacs-format-function ()
  "Format the whole buffer."
;;  (c-set-style "stroustrup")

(c-set-offset 'case-label ' +)
(c-set-offset 'brace-list-intro ' +)
(c-set-offset 'defun-open ' 0)
(c-set-offset 'defun-block-intro ' +)
(c-set-offset 'substatement ' +)
(c-set-offset 'substatement-open ' +)
(c-set-offset 'statement-block-intro ' +)
(c-set-offset 'statement-case-intro ' +)
(c-set-offset 'statement-case-open ' +)

   (setq default-tab-width 8)
   (setq c-basic-offset 8)
   (setq indent-tabs-mode nil)

   (indent-region (point-min) (point-max) nil)
   (untabify (point-min) (point-max))
   (whitespace-cleanup-region (point-min) (point-max))
   (save-buffer)
)
