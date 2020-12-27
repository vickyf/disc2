# DISC 2: 

**Title**: Emergence of border-ownership by large-scale consistency and long-range interactions: Neuro-computational model to reflect global configurations

**Status**: Under Review

**Abstract**:
The visual system performs remarkably well to perceive depth order of surfaces without stereo disparity, indicating the importance of figure-ground organization based on pictorial cues. To understand how figure-ground organization emerges, it is essential to find out how the global configuration of image is reflected. In the past, many neuro-computational models to reproduce figure-ground organization implemented algorithms to give a bias to convex regions. However, in certain conditions, a convex region can be perceived as a hole and a non-convex region as figural. This occurs when the surface properties of the convex area are consistent with the background and, hence, they are grouped together in our perception. We argue that large-scale consistency of surface properties is reflected in the border-ownership computation. We developed a model, called DISC2, that first analyses relationships between two border-ownership signals of all possible combinations in the image. It, then, enhances signals if they satisfy the following conditions: 1. the two signals fit to convex configuration, 2. the surface properties at the locations of the two signals are consistent. The strength of the enhancement decays with distance between the signals. The model gives extremely robust responses to various images with complexities both in shapes and depth orders. Furthermore, we developed an advanced version of the model (“augmented model”) where the global computation above interacts with local computation of co-curvilinearity, which further enhanced the robust nature of the model. The results suggest the involvement of similar computational processes in the brain for figure-ground organization.

## Supporting Files and Documentation

- Images used in the paper: https://www.dropbox.com/sh/y1revkz2iutj9t9/AABKhK3U01RJnuvFAAvtO5Jha?dl=0
- Outputs of the model: https://www.dropbox.com/sh/nbpv6vtf1uxy2k5/AABXHs1ktiO_A3BLdGLT7Hfha?dl=0
- Gif movies mentioned in the paper: https://www.dropbox.com/sh/hvtb9bf7n4aszlz/AAD8oJodjXylHbDplrkgpsw_a?dl=0

## Model Code

### Requirements
- MATLAB
- Image Processing Toolbox
- Statistics and Machine Learning Toolbox
- MATLAB Coder

### Setup
To be able to run the code, please run the setup function first in MATLAB console
```
setup
```
This will create the appropriate user files, compile the code and add the directory to the path.

**!Make sure you add the whole disc2 directory to your MATLAB path**

## Running the code
To run the code you can use run_disc_main. In this function you can:
1. Change the image you want to process `stim_name`
2. Use `preferences_user` to select a different input and output folder
3. Use `disc_params_user` to change any model parameters, note the ones set in `disc_params_default` are those used in the paper
4. Set `DiscParams.weightLCL` to 0.1 if you want to try out the augmented version of the model

After running this code results will be shown to you.
