;; MELPA Package-manager enabled code
(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;; Comment/uncomment this line to enable MELPA Stable if desired.  See `package-archive-priorities`
;; and `package-pinned-packages`. Most users will not need or want to do this.
;;(add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)

;; Rainbow Delimiters Mode
(add-hook 'prog-mode-hook #'rainbow-delimiters-mode)
(add-hook 'foo-mode-hook #'rainbow-delimiters-mode)

;; #1
(menu-bar-mode 1) ;; إخفاء شريط القوائم
(tool-bar-mode -1) ;; إخفاء شريط الأدوات
(scroll-bar-mode 1) ;; إخفاء شريط التمرير
(blink-cursor-mode 1) ;; إيقاف وميض مؤشر الكتابة
(tooltip-mode 1) ;; إخفاء تلمحيات الماوس

(setq display-line-numbers 'relative) ;; إظهار خط الأعداد نسبي

;; #2 
;; النسخ الاحتياطي
(setq make-backup-files nil) ;; احفظ بنسخ احتياطية للملفات التي يجري تحريرها
(setq backup-directory-alist (quote ((".*" . "~/.emacs.d/backup-files/")))) ;; ضع جميع هذه الملفات في هذا المسار

;; مضاعفة السطر الحالي أو المنطقة المُحددة
(defun duplicate-current-line-or-region (arg)
  "Duplicates the current line or region ARG times.
If there's no region, the current line will be duplicated. However, if
there's a region, all lines that region covers will be duplicated."
  (interactive "p")
  (let (beg end (origin (point)))
    (if (and mark-active (> (point) (mark)))
        (exchange-point-and-mark))
    (setq beg (line-beginning-position))
    (if mark-active
        (exchange-point-and-mark))
    (setq end (line-end-position))
    (let ((region (buffer-substring-no-properties beg end)))
      (dotimes (i arg)
        (goto-char end)
        (newline)
        (insert region)
        (setq end (point)))
      (goto-char (+ origin (* (length region) arg) arg)))))

(global-set-key (kbd "C-c d") 'duplicate-current-line-or-region) ;; اختصار لوحة المفاتيح لتفعيل هذه الدالة

;; التبديل بين التقسيم العمودي والأفقي ضمن إطار ايماكس
(defun toggle-window-split ()
  (interactive)
  (if (= (count-windows) 2)
      (let* ((this-win-buffer (window-buffer))
	     (next-win-buffer (window-buffer (next-window)))
	     (this-win-edges (window-edges (selected-window)))
	     (next-win-edges (window-edges (next-window)))
	     (this-win-2nd (not (and (<= (car this-win-edges)
					 (car next-win-edges))
				     (<= (cadr this-win-edges)
					 (cadr next-win-edges)))))
	     (splitter
	      (if (= (car this-win-edges)
		     (car (window-edges (next-window))))
		  'split-window-horizontally
		'split-window-vertically)))
	(delete-other-windows)
	(let ((first-win (selected-window)))
	  (funcall splitter)
	  (if this-win-2nd (other-window 1))
	  (set-window-buffer (selected-window) this-win-buffer)
	  (set-window-buffer (next-window) next-win-buffer)
	  (select-window first-win)
	  (if this-win-2nd (other-window 1))))))
(global-set-key (kbd "C-x |") 'toggle-window-split) ;; اختصار لوحة المفاتيح لتفعيل هذه الدالة

;; #3
(global-hl-line-mode -1) ;; إبراز السطر الحالي
(electric-pair-mode 1) ;; إغلاق تلقائي للأقواس
(show-paren-mode 1) ;; إبراز الأقواس عند الوقوف عليها
(setq isearch-allow-scroll t) ;; السماح بالسكرول دون الخروج من عملية البحث الحالية
(global-visual-line-mode 1) ;; الأسطر هي الأسطر المرئية، يُشبه خيار إلتفاف الأسطر في باقي المحررات

;; #4
(global-anzu-mode 1)

;; استخدام نظام البحث البديل آيفي
;; ivy + ivy-rich + smex + flx
(require 'swiper)
(require 'smex)
(require 'flx)
(require 'ivy-rich)
(ivy-mode 1)
(ivy-rich-mode 1)
(setq ivy-virtual-abbreviate 'full)
(setq ivy-rich-path-style 'abbrev)
(setq enable-recursive-minibuffers t)
(global-set-key (kbd "M-s M-p") 'swiper)
(global-set-key (kbd "M-x") 'counsel-M-x)
(global-set-key (kbd "C-x C-f") 'counsel-find-file)
(global-set-key (kbd "<f1> f") 'counsel-describe-function)
(global-set-key (kbd "<f1> v") 'counsel-describe-variable)
(global-set-key (kbd "<f1> l") 'counsel-find-library)
(global-set-key (kbd "<f2> i") 'counsel-info-lookup-symbol)
(global-set-key (kbd "<f2> u") 'counsel-unicode-char)
(global-set-key (kbd "C-c g") 'counsel-git)
(global-set-key (kbd "C-c j") 'counsel-git-grep)
(global-set-key (kbd "C-c k") 'counsel-rg)
(global-set-key (kbd "C-x l") 'counsel-locate)
(global-set-key (kbd "C-S-o") 'counsel-rhythmbox)
(global-set-key (kbd "C-x B") 'ivy-switch-buffer-other-window)
(define-key minibuffer-local-map (kbd "C-r") 'counsel-minibuffer-history)
(setq ivy-re-builders-alist
      '((swiper . ivy--regex-plus)
	(t . ivy--regex-fuzzy)))
(ivy-set-display-transformer
 'counsel-projectile-switch-to-buffer 'ivy-switch-buffer-rich-transformer)

;; #5 
;; حذف النص المُحدد عند إدراج نص جديد
(delete-selection-mode +1)

;; إظهار رقم العمود الحالي في شريط الحالة
(column-number-mode +1)

;; تغيير الخط المسؤول عن عرض النصوص العربية فقط
(set-fontset-font "fontset-default"
		  'arabic
		  (font-spec :family "Kawkab Mono" :size 30))


(setq mouse-wheel-scroll-amount '(2))  ;; قم بالتمرير سطر واحد في كل مرة
(setq mouse-wheel-progressive-speed nil) ;; لا تمرر أسطر كثيرة عند تسريع التمرير

;; Emacs setting
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default-input-method nil)
 '(display-line-numbers 'relative)
 '(package-selected-packages
   '(gruvbox-theme darktooth-theme solarized-theme dired-subtree avy-zap trie swiper-helm smex rainbow-delimiters posframe org-noter-pdftools markdown-mode ivy-rich flx dash counsel avy anzu)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(global-set-key (kbd "C-:") 'avy-goto-char) ;; القفز إلى حرف ما
(global-set-key (kbd "C-'") 'avy-goto-char-2) ;; القفز إلى حرف باستخدام حرفين
(global-set-key (kbd "M-g f") 'avy-goto-line) ;; القفز إلى سطر
(global-set-key (kbd "M-g w") 'avy-goto-word-1) ;; القفز إلى كلمة باستخدام حرفها الأول
(global-set-key (kbd "M-g e") 'avy-goto-word-0) ;; القفز إلى أي كلمة من كلمات البفر

;; (load-theme 'solarized-dark t)
;;(load-theme 'solarized-light t)
;; (load-theme 'darktooth t)
;;(load-theme 'gruvbox-dark-soft t)
;;(load-theme 'gruvbox-dark-medium t)
;;(load-theme 'gruvbox-dark-hard t)
(load-theme 'gruvbox-light-soft t)
;;(load-theme 'gruvbox-light-medium t)
;;(load-theme 'gruvbox-light-hard t)
