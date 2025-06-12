# Digital Image Processing

A curated collection of 100+ image processing exercises in C, organized into 20 topics. Each exercise focuses on fundamental operations such as filtering, segmentation, morphology, and compression implemented from scratch without external libraries. The goal is to provide hands-on, low-level understanding of how image processing algorithms work internally.


## 01 - Low complexity image I/O

Basic functions for reading and writing common image file formats such as PPM and BMP, along with reusable image structures and utilities.

| File | Description | Reference |
|------|-------------|-----------|
| [01_image_io/read_ppm.c](01_image_io/read_ppm.c) | Reads PPM files (P3/P6) | [PPM Format Specification](https://netpbm.sourceforge.net/doc/ppm.html) |
| [01_image_io/write_ppm.c](01_image_io/write_ppm.c) | Writes PPM images | [PPM Format Specification](https://netpbm.sourceforge.net/doc/ppm.html) |
| [01_image_io/read_bmp.c](01_image_io/read_bmp.c) | Create a basic BMP reader | [BMP File Format](https://en.wikipedia.org/wiki/BMP_file_format) |
| [01_image_io/write_bmp.c](01_image_io/write_bmp.c) | Create a BMP writer | [BMP File Format](https://en.wikipedia.org/wiki/BMP_file_format) |
| [01_image_io/gray_to_ppm.c](01_image_io/gray_to_ppm.c) | Converts grayscale (PGM-style) image to RGB (false color) | [PGM Format](https://netpbm.sourceforge.net/doc/pgm.html) |

## 02 - Color Spaces

This topic covers transformations between common color spaces such as RGB, HSV, and YCbCr. These conversions are foundational for tasks like segmentation, enhancement, and compression, enabling better separation of luminance and chrominance or isolating hue-based features.

| File | Description | Reference |
|------|-------------|-----------|
| [02_color_spaces/rgb_to_gray.c](02_color_spaces/rgb_to_gray.c) | RGB to grayscale conversion | [Convert RGB to Grayscale](https://www.baeldung.com/cs/convert-rgb-to-grayscale) |
| [02_color_spaces/rgb_to_hsv.c](02_color_spaces/rgb_to_hsv.c) | RGB → HSV conversion | [RGB to HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) |
| [02_color_spaces/hsv_to_rgb.c](02_color_spaces/hsv_to_rgb.c) | HSV → RGB conversion | [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) |
| [02_color_spaces/rgb_to_ycbcr.c](02_color_spaces/rgb_to_ycbcr.c) | RGB → YCbCr conversion | [YCbCr Color Space](https://en.wikipedia.org/wiki/YCbCr) |
| [02_color_spaces/hsv_threshold.c](02_color_spaces/hsv_threshold.c) | Basic HSV thresholding for color segmentation | [Color Thresholding](https://docs.opencv.org/3.4/da/d97/tutorial_threshold_inRange.html) |

## 03 - Linear Filters

This topic explores linear filtering techniques commonly used for image smoothing, sharpening, and edge enhancement. Linear filters operate via convolution and are essential for tasks such as noise reduction and feature enhancement.

| File | Description | Reference |
|------|-------------|-----------|
| [03_linear_filters/mean_filter.c](03_linear_filters/mean_filter.c) | Mean filter for basic smoothing | [Mean Filter](https://homepages.inf.ed.ac.uk/rbf/HIPR2/mean.htm) |
| [03_linear_filters/gaussian_filter.c](03_linear_filters/gaussian_filter.c) | Gaussian smoothing filter | [Gaussian Smoothing](https://homepages.inf.ed.ac.uk/rbf/HIPR2/gsmooth.htm) |
| [03_linear_filters/laplacian_filter.c](03_linear_filters/laplacian_filter.c) | Laplacian filter for second-order edge detection | [Laplacian Filter](https://homepages.inf.ed.ac.uk/rbf/HIPR2/log.htm) |
| [03_linear_filters/sharpen_filter.c](03_linear_filters/sharpen_filter.c) | Image sharpening using kernel convolution | [Image Sharpening](https://homepages.inf.ed.ac.uk/rbf/HIPR2/unsharp.htm) |
| [03_linear_filters/separable_gaussian.c](03_linear_filters/separable_gaussian.c) | Optimized separable 1D Gaussian filtering | [Separable Filters](https://en.wikipedia.org/wiki/Separable_filter) |

## 04 - Non-linear Filters

Non-linear filters are especially useful for preserving edges while removing noise. Unlike linear filters, they do not rely on convolution and often depend on sorting or rank-based operations within local neighborhoods.

| File | Description | Reference |
|------|-------------|-----------|
| [04_nonlinear_filters/median_filter.c](04_nonlinear_filters/median_filter.c) | Removes salt-and-pepper noise using median filter | [Median Filter](https://homepages.inf.ed.ac.uk/rbf/HIPR2/median.htm) |
| [04_nonlinear_filters/min_filter.c](04_nonlinear_filters/min_filter.c) | Minimum filter for local darkening | [Morphological Erosion](https://homepages.inf.ed.ac.uk/rbf/HIPR2/erode.htm) |
| [04_nonlinear_filters/max_filter.c](04_nonlinear_filters/max_filter.c) | Maximum filter for local brightening | [Morphological Dilation](https://homepages.inf.ed.ac.uk/rbf/HIPR2/dilate.htm) |
| [04_nonlinear_filters/mode_filter.c](04_nonlinear_filters/mode_filter.c) | Mode filter using most frequent pixel in kernel | [Mode Filter](https://www.roborealm.com/help/Mode.php) |
| [04_nonlinear_filters/adaptive_median.c](04_nonlinear_filters/adaptive_median.c) | Adaptive median filter for better edge preservation | [Image Restoration using Adaptive Median Filtering – IRJET](https://www.irjet.net/archives/V6/i10/IRJET-V6I10148.pdf) |


## 05 - Edge Detection

Edge detection highlights sharp changes in image intensity, making it fundamental for feature extraction, segmentation, and object recognition. This topic includes classic gradient-based detectors and modern multi-stage techniques.

| File | Description | Reference |
|------|-------------|-----------|
| [05_edge_detection/sobel_filter.c](05_edge_detection/sobel_filter.c) | Sobel filter using first-order gradients | [Sobel Operator – Wikipedia](https://en.wikipedia.org/wiki/Sobel_operator) |
| [05_edge_detection/prewitt_filter.c](05_edge_detection/prewitt_filter.c) | Prewitt filter for edge detection | [Prewitt Operator – Tutorialspoint](https://www.tutorialspoint.com/dip/prewitt_operator.htm) |
| [05_edge_detection/roberts_filter.c](05_edge_detection/roberts_filter.c) | Roberts cross operator for fine edges | [Roberts Cross – Wikipedia](https://en.wikipedia.org/wiki/Roberts_cross) |
| [05_edge_detection/canny_edge.c](05_edge_detection/canny_edge.c) | Canny edge detector with non-max suppression and hysteresis | [Canny Edge Detector – Wikipedia](https://en.wikipedia.org/wiki/Canny_edge_detector) |
| [05_edge_detection/edge_map_overlay.c](05_edge_detection/edge_map_overlay.c) | Overlays binary edge map on original image | [Edge Detection – Wikipedia](https://en.wikipedia.org/wiki/Edge_detection) |


## 06 - Morphology

Morphological operations are shape-based image processing techniques widely used in binary and grayscale image analysis. They enable object segmentation, noise removal, and shape refinement using operations like erosion, dilation, opening, and closing.

| File | Description | Reference |
|------|-------------|-----------|
| [06_morphology/dilation.c](06_morphology/dilation.c) | Morphological dilation (expands foreground regions) | [Dilation – Wikipedia](https://en.wikipedia.org/wiki/Dilation_(morphology)) |
| [06_morphology/erosion.c](06_morphology/erosion.c) | Morphological erosion (shrinks foreground regions) | [Erosion – Wikipedia](https://en.wikipedia.org/wiki/Erosion_(morphology)) |
| [06_morphology/opening.c](06_morphology/ope[48;66;223;2244;3568tning.c) | Opening: erosion followed by dilation | [Opening (morphology) – Wikipedia](https://en.wikipedia.org/wiki/Opening_(morphology)) |
| [06_morphology/closing.c](06_morphology/closing.c) | Closing: dilation followed by erosion | [Closing (morphology) – Wikipedia](https://en.wikipedia.org/wiki/Closing_(morphology)) |
| [06_morphology/morphological_edge.c](06_morphology/morphological_edge.c) | Morphological edge detection via gradient (dilation - erosion) | [Morphological Gradient – Wikipedia](https://en.wikipedia.org/wiki/Mathematical_morphology#Morphological_gradient) |


## 07 - Histogram

Histogram based techniques analyze the frequency distribution of pixel intensities in an image. They are widely used in tasks like contrast enhancement, normalization, and thresholding. This topic includes both visualization and histogram based transformations.

| File | Description | Reference |
|------|-------------|-----------|
| [07_histogram/histogram.c](07_histogram/histogram.c) | Computes and plots image histogram | [Image Histogram – Wikipedia](https://en.wikipedia.org/wiki/Image_histogram) |
| [07_histogram/equalize_histogram.c](07_histogram/equalize_histogram.c) | Performs histogram equalization to enhance contrast | [Histogram Equalization – Wikipedia](https://en.wikipedia.org/wiki/Histogram_equalization) |
| [07_histogram/stretch_contrast.c](07_histogram/stretch_contrast.c) | Performs contrast stretching using min/max normalization | [Normalization (Image Processing) – Wikipedia](https://en.wikipedia.org/wiki/Normalization_(image_processing)) |
| [07_histogram/clip_histogram.c](07_histogram/clip_histogram.c) | Applies histogram clipping (limited contrast enhancement) | [Contrast Limited Adaptive Histogram Equalization (CLAHE) – Wikipedia](https://en.wikipedia.org/wiki/Adaptive_histogram_equalization#Contrast_Limited_AHE) |
| [07_histogram/histogram_overlay.c](07_histogram/histogram_overlay.c) | Overlays histogram on image preview or chart | [Histogram Visualization – OpenCV Documentation](https://docs.opencv.org/4.x/d1/db7/tutorial_py_histogram_begins.html) |



## 08 - Segmentation

Image segmentation is the process of partitioning an image into meaningful regions, usually to separate objects or highlight structures. This topic includes classical thresholding methods as well as clustering and region based approaches.

| Arquivo | Descrição | Referência |
|---------|-----------|------------|
| [08_segmentation/thresholding.c](08_segmentation/thresholding.c) | Limiarização simples com valor fixo | [Thresholding (Image Processing) – Wikipedia](https://en.wikipedia.org/wiki/Thresholding_(image_processing)) |
| [08_segmentation/otsu_threshold.c](08_segmentation/otsu_threshold.c) | Método de Otsu para seleção automática de limiar | [Otsu's Method – Wikipedia](https://en.wikipedia.org/wiki/Otsu%27s_method) |
| [08_segmentation/region_growing.c](08_segmentation/region_growing.c) | Segmentação por crescimento de regiões baseada em similaridade de intensidade | [Region Growing – Wikipedia](https://en.wikipedia.org/wiki/Region_growing) |
| [08_segmentation/kmeans_segmentation.c](08_segmentation/kmeans_segmentation.c) | Segmentação usando clustering K-means | [K-means Clustering – Wikipedia](https://en.wikipedia.org/wiki/K-means_clustering) |
| [08_segmentation/segmentation_visual.c](08_segmentation/segmentation_visual.c) | Sobreposição da máscara de segmentação na imagem original | [Visualização de Segmentação – OpenCV Docs](https://docs.opencv.org/4.x/d3/db4/tutorial_py_watershed.html) |


## 09 - Geometry

Geometric transformations alter the spatial configuration of images. These operations are essential for tasks like resizing, rotating, correcting distortions, or mapping between coordinate systems.

| File | Description | Reference |
|------|-------------|-----------|
| [09_geometry/resize_nearest.c](09_geometry/resize_nearest.c) | Image resizing using nearest-neighbor interpolation | [Nearest-Neighbor Interpolation – Wikipedia](https://en.wikipedia.org/wiki/Nearest-neighbor_interpolation) |
| [09_geometry/resize_bilinear.c](09_geometry/resize_bilinear.c) | Image resizing using bilinear interpolation | [Bilinear Interpolation – Wikipedia](https://en.wikipedia.org/wiki/Bilinear_interpolation) |
| [09_geometry/rotate_image.c](09_geometry/rotate_image.c) | Image rotation by arbitrary angle | [Image Rotation – OpenCV Docs](https://docs.opencv.org/4.x/da/d54/group__imgproc__transform.html) |
| [09_geometry/affine_transform.c](09_geometry/affine_transform.c) | Applies affine transformation matrix to an image | [Affine Transformation – Wikipedia](https://en.wikipedia.org/wiki/Affine_transformation) |
| [09_geometry/geometry_overlay.c](09_geometry/geometry_overlay.c) | Visual comparison of original and transformed images | [Image Transformation Visualization – OpenCV](https://docs.opencv.org/4.x/da/d6e/tutorial_py_geometric_transformations.html) |

## 10 - Compression

Image compression reduces storage and transmission costs by encoding images more efficiently, often with minimal loss in quality. This topic covers both lossless (e.g., RLE, Huffman) and practical conversion strategies.

| File | Description | Reference |
|------|-------------|-----------|
| [10_compression/rle_compress.c](10_compression/rle_compress.c) | Compresses image data using Run-Length Encoding | [Run-Length Encoding – Wikipedia](https://en.wikipedia.org/wiki/Run-length_encoding) |
| [10_compression/rle_decompress.c](10_compression/rle_decompress.c) | Decompresses RLE-encoded image data | [Run-Length Encoding – Wikipedia](https://en.wikipedia.org/wiki/Run-length_encoding) |
| [10_compression/ppm_to_rle.c](10_compression/ppm_to_rle.c) | Converts PPM image to RLE-compressed format | [Netpbm Format – PPM](https://netpbm.sourceforge.net/doc/ppm.html) |
| [10_compression/huffman_encode.c](10_compression/huffman_encode.c) | Encodes image data using Huffman coding | [Huffman Coding – Wikipedia](https://en.wikipedia.org/wiki/Huffman_coding) |
| [10_compression/compression_analysis.c](10_compression/compression_analysis.c) | Measures entropy and theoretical compression limits of the image | [Shannon Entropy – Wikipedia](https://en.wikipedia.org/wiki/Entropy_(information_theory)) |


## 11 - Pointwise Operations

Pointwise operations modify each pixel independently based on its intensity value. These transformations are fundamental for tasks like tone correction, binarization, and contrast enhancement, and are often used as preprocessing steps.

| File | Description | Reference |
|------|-------------|-----------|
| [11_pointwise_ops/invert_colors.c](11_pointwise_ops/invert_colors.c) | Inverts pixel values to produce a negative image | [Negative Transformation – GeeksforGeeks](https://www.geeksforgeeks.org/negative-transformation-of-an-image-using-python-and-opencv/) |
| [11_pointwise_ops/gamma_correction.c](11_pointwise_ops/gamma_correction.c) | Applies gamma correction to adjust brightness non-linearly | [Gamma Correction – Wikipedia](https://en.wikipedia.org/wiki/Gamma_correction) |
| [11_pointwise_ops/log_transform.c](11_pointwise_ops/log_transform.c) | Compresses dynamic range using logarithmic scaling | [Log Transformation – GeeksforGeeks](https://www.geeksforgeeks.org/log-transformation-of-an-image-using-python-and-opencv/) |
| [11_pointwise_ops/threshold_binary.c](11_pointwise_ops/threshold_binary.c) | Converts image to binary using a fixed threshold | [Image Thresholding – Wikipedia](https://en.wikipedia.org/wiki/Thresholding_(image_processing)) |
| [11_pointwise_ops/pointwise_plot.c](11_pointwise_ops/pointwise_plot.c) | Visualizes the intensity transfer functions (log, gamma, negative) | [Intensity Transform Functions – OpenCV Docs](https://docs.opencv.org/4.x/d3/dc1/tutorial_basic_linear_transform.html) |


## 12 - FFT & Convolution

This topic explores image processing in the frequency domain using the Fast Fourier Transform (FFT). These techniques enable efficient convolution, filtering, and spectrum analysis, especially with large kernels. Understanding FFT is essential for advanced signal and image analysis.

| File | Description | Reference |
|------|-------------|-----------|
| [12_fft_convolution/fft1d.c](12_fft_convolution/fft1d.c) | Implements 1D Fast Fourier Transform (FFT) | [Fast Fourier Transform in Image Processing – GeeksforGeeks](https://www.geeksforgeeks.org/fast-fourier-transform-in-image-processing/) |
| [12_fft_convolution/fft2d.c](12_fft_convolution/fft2d.c) | Computes 2D FFT of an image | [Fast Fourier Transform in Image Processing – GeeksforGeeks](https://www.geeksforgeeks.org/fast-fourier-transform-in-image-processing/) |
| [12_fft_convolution/ifft2d.c](12_fft_convolution/ifft2d.c) | Performs inverse 2D FFT to reconstruct the image | [Fast Fourier Transform in Image Processing – GeeksforGeeks](https://www.geeksforgeeks.org/fast-fourier-transform-in-image-processing/) |
| [12_fft_convolution/freq_filter.c](12_fft_convolution/freq_filter.c) | Applies low-pass and high-pass filters in the frequency domain | [Frequency Domain Filters – GeeksforGeeks](https://www.geeksforgeeks.org/frequency-domain-filters-and-its-types/) |
| [12_fft_convolution/fft_visualization.c](12_fft_convolution/fft_visualization.c) | Visualizes FFT magnitude and phase spectra | [FFT Visualization – Paul Bourke](https://paulbourke.net/miscellaneous/imagefilter/) |


## 13 - Corner Detection

Corner detection is a fundamental technique in computer vision used to identify points in an image where the intensity changes sharply in multiple directions. These points are crucial for tasks like tracking, image matching, and object recognition.

| File | Description | Reference |
|------|-------------|-----------|
| [13_corner_detection/harris_corner.c](13_corner_detection/harris_corner.c) | Implements the Harris corner detector using gradient matrices | [Harris Corner Detection – OpenCV Docs](https://docs.opencv.org/4.x/dc/d0d/tutorial_py_features_harris.html) |
| [13_corner_detection/shi_tomasi.c](13_corner_detection/shi_tomasi.c) | Detects corners using Shi-Tomasi's "Good Features to Track" method | [Shi-Tomasi Corner D[48;74;255;2220;3570tetector – OpenCV Docs](https://docs.opencv.org/4.x/d4/d8c/tutorial_py_shi_tomasi.html) |
| [13_corner_detection/nonmax_suppression.c](13_corner_detection/nonmax_suppression.c) | Applies non-maximum suppression to retain the strongest corners | [Non-Maximum Suppression – OpenCV FAST Tutorial](https://docs.opencv.org/4.x/df/d0c/tutorial_py_fast.html) |
| [13_corner_detection/corner_visualization.c](13_corner_detection/corner_visualization.c) | Visualizes detected corners on the input image | [Harris Corner Detection – OpenCV Docs](https://docs.opencv.org/4.x/dc/d0d/tutorial_py_features_harris.html) |
| [13_corner_detection/corner_refinement.c](13_corner_detection/corner_refinement.c) | Refines corner positions to sub-pixel accuracy | [Corner SubPixel Accuracy – OpenCV Docs](https://docs.opencv.org/4.x/dc/d0d/tutorial_py_features_harris.html) |


## 14 - Denoising

Image denoising aims to remove unwanted noise while preserving important features such as edges and textures. This topic covers both basic and advanced filters designed to suppress different types of noise.

| File | Description | Reference |
|------|-------------|-----------|
| [14_denoising/salt_pepper_noise.c](14_denoising/salt_pepper_noise.c) | Removes salt-and-pepper noise using a median filter | [Median Filtering – OpenCV Docs](https://docs.opencv.org/4.x/d4/d13/tutorial_py_filtering.html) |
| [14_denoising/gaussian_noise.c](14_denoising/gaussian_noise.c) | Reduces Gaussian noise using a Gaussian blur | [Gaussian Filtering – OpenCV Docs](https://docs.opencv.org/4.x/d4/d13/tutorial_py_filtering.html) |
| [14_denoising/bilateral_filter.c](14_denoising/bilateral_filter.c) | Applies bilateral filtering to preserve edges while denoising | [Bilateral Filtering – OpenCV Docs](https://docs.opencv.org/4.x/d4/d13/tutorial_py_filtering.html) |
| [14_denoising/non_local_means.c](14_denoising/non_local_means.c) | Uses non-local means for high-quality noise removal | [Non-Local Means Denoising – OpenCV Docs](https://docs.opencv.org/3.4/d5/d69/tutorial_py_non_local_means.html) |
| [14_denoising/denoise_comparison.c](14_denoising/denoise_comparison.c) | Compares denoising methods side-by-side | [Image Denoising Overview – OpenCV Docs](https://docs.opencv.org/3.4/d5/d69/tutorial_py_non_local_means.html) |


## 15 - Grayscale Operations

Grayscale image processing focuses on operations that enhance or analyze images with a single luminance channel. These techniques are widely used in medical imaging, document analysis, and low-level computer vision.

| File | Description | Reference |
|------|-------------|-----------|
| [15_grayscale_ops/gray_histogram.c](15_grayscale_ops/gray_histogram.c) | Computes the histogram of a grayscale image | [Image Histogram – Wikipedia](https://en.wikipedia.org/wiki/Image_histogram) |
| [15_grayscale_ops/gray_equalization.c](15_grayscale_ops/gray_equalization.c) | Applies histogram equalization to improve contrast | [Histogram Equalization – Wikipedia](https://en.wikipedia.org/wiki/Histogram_equalization) |
| [15_grayscale_ops/gray_thresholding.c](15_grayscale_ops/gray_thresholding.c) | Performs binary thresholding on a grayscale image | [Thresholding – Wikipedia](https://en.wikipedia.org/wiki/Thresholding_(image_processing)) |
| [15_grayscale_ops/gray_morphology.c](15_grayscale_ops/gray_morphology.c) | Performs erosion and dilation on grayscale images | [Morphological Operations – Wikipedia](https://en.wikipedia.org/wiki/Mathematical_morphology) |
| [15_grayscale_ops/gray_utils.c](15_grayscale_ops/gray_utils.c) | Common helper functions for grayscale processing | [Grayscale Image – Wikipedia](https://en.wikipedia.org/wiki/Grayscale) |


## 16 - Shape Recognition

Shape recognition involves detecting and analyzing geometric structures like contours, lines, and circles in images. These techniques are fundamental for object detection, character recognition, and scene understanding.

| File | Description | Reference |
|------|-------------|-----------|
| [16_shape_recognition/contour_detection.c](16_shape_recognition/contour_detection.c) | Detects object contours in binary images | [Contour Detection – OpenCV Docs](https://docs.opencv.org/3.4/d4/d73/tutorial_py_contours_begin.html) |
| [16_shape_recognition/bounding_box.c](16_shape_recognition/bounding_box.c) | Computes bounding boxes around detected shapes | [Contour Features – OpenCV Docs](https://docs.opencv.org/4.x/dd/d49/tutorial_py_contour_features.html) |
| [16_shape_recognition/hough_lines.c](16_shape_recognition/hough_lines.c) | Detects straight lines using the Hough Transform | [Hough Line Transform – OpenCV Docs](https://docs.opencv.org/4.x/d6/d10/tutorial_py_houghlines.html) |
| [16_shape_recognition/hough_circles.c](16_shape_recognition/hough_circles.c) | Detects circular shapes using the Hough Circle Transform | [Hough Circle Transform – OpenCV Docs](https://docs.opencv.org/4.x/da/d53/tutorial_py_houghcircles.html) |
| [16_shape_recognition/shape_utils.c](16_shape_recognition/shape_utils.c) | Utility functions for shape analysis and drawing | [Contour Features – OpenCV Docs](https://docs.opencv.org/4.x/dd/d49/tutorial_py_contour_features.html) |


## 17 - Stereo Vision

Stereo vision enables depth perception by analyzing the disparity between two images captured from slightly different viewpoints. This technique is essential for 3D reconstruction, autonomous navigation, and robotic perception.

| File | Description | Reference |
|------|-------------|-----------|
| [17_stereo_vision/stereo_calibration.c](17_stereo_vision/stereo_calibration.c) | Calibrates stereo camera setup using a checkerboard pattern | [Stereo Camera Calibration and Triangulation with OpenCV and Python](https://temugeb.github.io/opencv/python/2021/02/02/stereo-camera-calibration-and-triangulation.html) |
| [17_stereo_vision/rectify_images.c](17_stereo_vision/rectify_images.c) | Rectifies stereo images to align epipolar lines | [Stereo Vision in OpenCV](https://www.opencvhelp.org/tutorials/advanced/stereo-vision/) |
| [17_stereo_vision/disparity_map.c](17_stereo_vision/disparity_map.c) | Computes disparity map using StereoBM algorithm | [Depth Map from Stereo Images – OpenCV Documentation](https://docs.opencv.org/4.x/dd/d53/tutorial_py_depthmap.html) |
| [17_stereo_vision/depth_estimation.c](17_stereo_vision/depth_estimation.c) | Estimates depth from disparity using triangulation | [Stereo Camera Depth Estimation With OpenCV (Python/C++)](https://learnopencv.com/depth-perception-using-stereo-camera-python-c/) |
| [17_stereo_vision/3d_reconstruction.c](17_stereo_vision/3d_reconstruction.c) | Reconstructs 3D point cloud from stereo images | [Introduction to Epipolar Geometry and Stereo Vision](https://learnopencv.com/introduction-to-epipolar-geometry-and-stereo-vision/) |


## 18 - Motion Detection

Motion detection involves identifying changes in an image sequence to detect moving objects. This topic covers various techniques such as frame differencing,  background subtraction, and optical flow, which are fundamental in surveillance,  activity recognition, and video analysis.

| File | Description | Reference |
|------|-------------|-----------|
| [18_motion_detection/frame_diff.c](18_motion_detection/frame_diff.c) | Implements basic frame differencing for motion detection | [Motion Detection: Part 1](https%3A%2F%2Fmedium.com%2F%40itberrios6%2Fintroduction-to-motion-detection-part-1-e031b0bb9bb2) |
| [18_motion_detection/bg_subtraction.c](18_motion_detection/bg_subtraction.c) | Applies background subtraction using MOG2 algorithm | [Background Subtraction – OpenCV Documentation](https://docs.opencv.org/3.4/d1/dc5/tutorial_background_subtraction.html) |
| [18_motion_detection/optical_flow.c](18_motion_detection/optical_flow.c) | Computes dense optical flow using Farneback method | [Optical Flow in OpenCV (C++/Python) – LearnOpenCV](https://learnopencv.com/optical-flow-in-opencv/) |
| [18_motion_detection/motion_tracking.c](18_motion_detection/motion_tracking.c) | Tracks moving objects using contours and bounding boxes | [Basic Motion Detection and Tracking with Python and OpenCV – PyImageSearch](https://pyimagesearch.com/2015/05/25/basic-motion-detection-and-tracking-with-python-and-opencv/) |
| [18_motion_detection/motion_utils.c](18_motion_detection/motion_utils.c) | Utility functions for motion detection and visualization | [Moving Object Detection with OpenCV – LearnOpenCV](https://learnopencv.com/moving-object-detection-with-opencv/) |


## 19 - Object Tracking

Object tracking involves following the movement of objects across video frames, maintaining their identities over time. This is crucial for applications like surveillance, traffic monitoring, and human-computer interaction.

| File | Description | Reference |
|------|-------------|-----------|
| [19_object_tracking/single_tracker.c](19_object_tracking/single_tracker.c) | Implements single-object tracking using OpenCV's built-in trackers (e.g., CSRT, KCF) | [OpenCV Object Tracking – PyImageSearch](https://pyimagesearch.com/2018/07/30/opencv-object-tracking/) |
| [19_object_tracking/multi_tracker.c](19_object_tracking/multi_tracker.c) | Tracks multiple objects simultaneously using OpenCV's MultiTracker API | [MultiTracker: Multiple Object Tracking using OpenCV – LearnOpenCV](https://learnopencv.com/multitracker-multiple-object-tracking-using-opencv-c-python/) |
| [19_object_tracking/kalman_filter.c](19_object_tracking/kalman_filter.c) | Applies Kalman filtering for predictive tracking of object motion | [Object Tracking using OpenCV (C++/Python) – LearnOpenCV](https://learnopencv.com/object-tracking-using-opencv-cpp-python/) |
| [19_object_tracking/meanshift_camshift.c](19_object_tracking/meanshift_camshift.c) | Demonstrates object tracking using MeanShift and CamShift algorithms | [Introduction to OpenCV Tracker – OpenCV Docs](https://docs.opencv.org/4.x/d2/d0a/tutorial_introduction_to_tracker.html) |
| [19_object_tracking/tracking_utils.c](19_object_tracking/tracking_utils.c) | Utility functions for initializing and managing trackers | [Getting Started With Object Tracking Using OpenCV – GeeksforGeeks](https://www.geeksforgeeks.org/getting-started-with-object-tracking-using-opencv/) |


## 20 - Object Detection

Object detection involves identifying and localizing objects within images or video frames. This topic explores various techniques, from traditional methods like Haar Cascades to modern deep learning approaches such as YOLO and SSD, utilizing OpenCV's capabilities.

| File | Description | Reference |
|------|-------------|-----------|
| [20_object_detection/haar_cascade.c](20_object_detection/haar_cascade.c) | Implements object detection using Haar Cascades | [Detect an object with OpenCV-Python – GeeksforGeeks](https://www.geeksforgeeks.org/detect-an-object-with-opencv-python/) |
| [20_object_detection/yolo_detection.c](20_object_detection/yolo_detection.c) | Performs object detection using YOLOv3 with OpenCV's DNN module | [YOLO object detection with OpenCV – PyImageSearch](https://pyimagesearch.com/2018/11/12/yolo-object-detection-with-opencv/) |
| [20_object_detection/ssd_detection.c](20_object_detection/ssd_detection.c) | Applies object detection using SSD with MobileNet in OpenCV | [Object detection with deep learning and OpenCV – PyImageSearch](https://pyimagesearch.com/2017/09/11/object-detection-with-deep-learning-and-opencv/) |
| [20_object_detection/dnn_utils.c](20_object_detection/dnn_utils.c) | Provides utility functions for loading and running DNN models in OpenCV | [Running pre-trained YOLO model in OpenCV – OpenCV Docs](https://docs.opencv.org/4.x/da/d9d/tutorial_dnn_yolo.html) |
| [20_object_detection/detection_comparison.c](20_object_detection/detection_comparison.c) | Compares performance and accuracy of different object detection methods | [Object Detection with YOLO and OpenCV: A Practical Guide – Medium](https%3A%2F%2Fmedium.com%2F%40tejasdalvi927%2Fobject-detection-with-yolo-and-opencv-a-practical-guide-cf7773481d11) |


