(package-initialize)

(add-to-list 'custom-theme-load-path "~/.emacs.d/themes/")
(load-theme 'zenburn t)

(custom-set-variables
 '(ecb-options-version "2.40")
 '(inhibit-startup-screen t))
(custom-set-faces)


(setq make-backup-files nil)
(progn
  (show-paren-mode 1)
  (setq show-paren-style 'parenthesis)
  (setq show-paren-style 'expression)
  (setq show-paren-style 'mixed)
  )

