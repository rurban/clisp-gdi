;; -*- Lisp -*- vim:filetype=lisp
;; some tests for GDI
;; clisp -E 1:1 -K full -modern -q -norc -i ../tests/tests -x '(run-test "gdi/test")'

(in-package :cs-user) #<package cs-common-lisp-user>

(listp (show (multiple-value-list (ext:module-info "GDI" t)) :pretty t)) t

(progn (defvar hdc (GDI::GetDC nil)) (if hdc t)) t
(integerp (defvar sy (GDI::GetDeviceCaps hdc GDI::LOGPIXELSY))) t
(defvar logfont (GDI::make-logfont
                 (- sy) 0 0 0 GDI::FW_BOLD 1 0 0 GDI::ANSI_CHARSET
                 GDI::OUT_TT_PRECIS GDI::CLIP_DEFAULT_PRECIS
                 GDI::PROOF_QUALITY GDI::VARIABLE_PITCH
                 "Times New Roman")) logfont
(progn (setq hfont (GDI::CreateFontIndirectA logfont))
       (typep hfont 'foreign-pointer)) t
(integerp (GDI::GetSystemMetrics GDI::SM_CXSCREEN)) t
(integerp (GDI::GetSystemMetrics GDI::SM_CYSCREEN)) t
(progn (setq hold (GDI::SelectObject hdc hfont))
       (typep hold 'foreign-pointer)) t
(GDI::SetTextColor hdc (GDI::make-rgb 0 0 #xff)) 0

(progn (GDI::SelectObject hdc hold) (GDI::DeleteObject hfont) t) t
