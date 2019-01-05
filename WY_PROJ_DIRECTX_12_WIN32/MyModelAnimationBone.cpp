// File name: [MyModelAnimationBone.cpp] (Copyright to Samil Chai)
// Work Session #0196: 2017-08-28
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NFlMelBVUkdTZ0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NFlMelBVUkdTZ0k
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4YjlmWEJxWlg3U3c%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4YjlmWEJxWlg3U3c
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4WVBNZXlBcUxUMlk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WVBNZXlBcUxUMlk
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class represents a single animation file.
//		This class holds the animation data to be rendered on DirectX 12 engine
//			to apply the animation onto the armature models.
//		This will be held by each MyModeArmature object and will hold every 
//			MyModelAnimationBone objects for having each collection of animation 
//			frame data MyModelAnimationBoneData objects inside.
//		Main purpose is to apply animation onto a MyModelArmature object.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each collection of animation 
//				frame data MyModelAnimationBoneData objects which is 
//				the collection of animation frame data values to be used to 
//				apply animation onto each armature bones on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the data values inside each MyModelAnimationBoneData
//				object over time frame to apply the animation onto each 
//				corresponding MyModelArmatureBone objects for animation.
//		The animation file exporting format is adjusted as follows:
//			Summary document: https://docs.google.com/document/d/1yXmmCSx_2r5GVpoty6Y1P1KIiSH8nzz7cffsHfHxTzo/edit#bookmark=kix.gxpvfxacvl9r
//			Custom exported animation file:
//				count - Number of pose bones i want to export the animation 
//						data with.
//				CU - Exported coordinate system option UP vector.
//				CF - Exported coordinate system option FORWARD vector.
//					bn - Current animation bone to export animation data with.
//					Animation data to be held by each animaiton bone object:
//						bt - Current animation frame bone tail coordinate.
//						bh - Current animation frame bone head coordinate.
//						<> - Current animation frame bone world matrix. 
//						tra - Current animation frame bone translation vector. 
//						rot - Current animation frame bone rotation quaternion. 
//						sca - Current animation frame bone scaling vector. 
// - [Commments]:
//		The main data structure to hold the MyModelAnimationBone objects is 
//		changed from array type ot std::vector type, because std::vector is 
//		more standard and safe to use then the manually implemented array or
//		data structure classes.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0041
//------------------------------------------------------------------------------
// [rev0002:WY:201708281820]
//------------------------------------------------------------------------------
// File name: [MyModelAnimationBone.cpp] (Copyright to Samil Chai)
// Work Session #0193: 2017-07-24
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4UEtXaWdRTEg1MEk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cUtkTHFRV2ZtdjQ%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4b3FsaWVPLUE2VEE%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class holds the animation data for each model armature bones
//			to be rendered on DirectX 12 engine
//		Will be held by each MyModeArmatureBone object and will hold each 
//			animation queue inside.
//		Main purpose is to manage animation for bone itself, and then
//			apply the animation by comparing the animation bone name with 
//			actual aramture bones name.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each animation queue which is 
//				the array type of XMFLOAT4X4 values on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the XMFLOAT4X4 values onto each MyModelArmatureBone's
//				update its CBV to apply the animation.
// - [Commments]:
//		Inner documents implemented using Javadoc.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0001:WY:2017261910]
//------------------------------------------------------------------------------
// File name: [MyModelAnimationBone.cpp] (Copyright to Samil Chai)
// Work Session #0188: 2017-07-18
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4UEtXaWdRTEg1MEk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cUtkTHFRV2ZtdjQ%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4b3FsaWVPLUE2VEE%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class holds the animation data for each model armature bones
//			to be rendered on DirectX 12 engine
//		Will be held by each MyModeArmatureBone object and will hold each 
//			animation queue inside.
//		Main purpose is to manage animation for bone itself, and then
//			apply the animation by comparing the animation bone name with 
//			actual aramture bones name.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each animation queue which is 
//				the array type of XMFLOAT4X4 values on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the XMFLOAT4X4 values onto each MyModelArmatureBone's
//				update its CBV to apply the animation.
// - [Commments]:
//		Basic methods implemented
//		This class object will be held by a single MyModelBone object, where 
//			this object will be holding XMFLOAT4X4 constant buffer data value 
//			for each frames to be updated for animation.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0000:WY:201707181800]
//------------------------------------------------------------------------------
//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################

#include "stdafx.h"
#include "MyModelAnimationBone.h"

// Default constructor.
MyModelAnimationBone::MyModelAnimationBone() {
	// Main data structure to hold the animation frame datas as std::vector of
	// MyModelAnimationBoneData objects.
	this->animationFrames 
		= new vector<MyModelAnimationBoneData *>();

	// Name of the animation bone.
	this->animationBoneName = new char[BUFSIZ]();
	std::fill(this->animationBoneName, this->animationBoneName + BUFSIZ, 0);

	// Current MyModelArmatureBone object pointer to assign current animation 
	// data with for rendering the animation of the armature.
	this->currentArmatureBone = NULL; // Set to NULL by default.
}

// General constructor 2.
MyModelAnimationBone::MyModelAnimationBone(
	MyModelArmatureBone *currentArmatureBone, 
	char *animationBoneName) {
	// Main data structure to hold the animation frame datas as std::vector of
	// MyModelAnimationBoneData objects.
	this->animationFrames
		= new vector<MyModelAnimationBoneData *>();

	// Name of the animation bone.
	strcpy(this->animationBoneName, animationBoneName);

	// Current MyModelArmatureBone object pointer to assign current animation 
	// data with for rendering the animation of the armature.
	this->currentArmatureBone = currentArmatureBone;
}

// Destructor.
MyModelAnimationBone::~MyModelAnimationBone() {
	// Main data structure to hold the imported array of XMFLOAT4X4 animation 
	// data as a Queue type data structure. 
	// (See Queue.h template class for more)
	if (this->animationFrames != NULL) {
		delete this->animationFrames;
		this->animationFrames = NULL;
	}
	// Name of the animation bone.
	if (this->animationBoneName != NULL) {
		delete this->animationBoneName;
		this->animationBoneName = NULL;
	}

	// Current MyModelArmatureBone object pointer to assign current animation 
	// data with for rendering the animation of the armature.
	if (this->currentArmatureBone != NULL) {
		delete this->currentArmatureBone;
		this->currentArmatureBone = NULL;
	}
}

/*
*	Getter - Member variable "animationBoneName".
*	<p>
*	This function is the getter for current MyModelAnimationBone object's
*		member variable "animationBoneName".
*		- Name of current MyModelAnimationBone object animation bone object
*		  loaded from animation file.
*	@return		Return current MyModelAnimationBone object's
*					member variable "animationBoneName"
*					string value.
*	@since		ver0038
*/
char *MyModelAnimationBone::getAnimationBoneName() {
	return this->animationBoneName;
}
/*
*	Setter - Member variable "animationBoneName".
*	<p>
*	This function is the setter for current MyModelAnimationBone object's
*		member variable "animationBoneName".
*		- Name of current MyModelAnimationBone object animation bone object
*		  loaded from animation file.
*	@param		animationBoneName		Bone name C-string value to set with.
*	@return		void
*	@since		ver0038
*/
void MyModelAnimationBone::setAnimationBoneName(char *animationBoneName) {
	strcpy(this->animationBoneName, animationBoneName);
}

/*
*	Getter - Member variable "currentArmatureBone".
*	<p>
*	This function is the getter for current MyModelAnimationBone object's
*		member variable "currentArmatureBone".
*		- Current MyModelAnimationBone object pointer to assign current animation 
*		  data with for rendering the animation of the armature.
*	@return		Return current MyModelAnimationBone object's
*					member variable "currentArmatureBone"
*					MyModelArmatureBone pointer.
*	@since		ver0038
*/
MyModelArmatureBone *MyModelAnimationBone::getCurrentArmatureBone() {
	return this->currentArmatureBone;
}

/*
*	Setter - Member variable "currentArmatureBone".
*	<p>
*	This function is the setter for current MyModelAnimationBone object's
*		member variable "currentArmatureBone".
*		- Current MyModelAnimationBone object pointer to assign current 
*		  animation data with, for rendering the animation of the armature.
*	@param		currentArmatureBone		MyModelArmatureBone object pointer to
*										set with.
*	@return		void
*	@since		ver0038
*/
void MyModelAnimationBone::setCurrentArmatureBone(
	MyModelArmatureBone *currentArmatureBone) {
	this->currentArmatureBone = currentArmatureBone;
}
/*
*	Getter - Member variable "animationFrames".
*	<p>
*	This function is the getter for current MyModelAnimationBone object's
*		member variable "animationFrames".
*		- Main std::vector type data structure to hold the imported array of 
*		  MyModelAnimationBoneData objects to be used to animate over time 
*		  frames.
*	@return		Return current MyModelAnimationBone object's
*					member variable "animationFrames"
*					vector<MyModelAnimationBoneData *> pointer.
*	@see		std::vector
*	@since		ver0041
*/
vector<MyModelAnimationBoneData *> *MyModelAnimationBone::getAnimationFrames() {
	return this->animationFrames;
}
/*
*	Setter - Member variable "currentArmatureBone".
*	<p>
*	This function is the setter for current MyModelAnimationBone object's
*		member variable "animationFrames".
*		- Main std::vector type data structure to hold the imported array of
*		  MyModelAnimationBoneData objects to be used to animate over time
*		  frames.
*	@param		animationFrames		vector<MyModelAnimationBoneData *> pointer
*									to set with.
*	@return		void
*	@see		std::vector
*	@since		ver0041
*/
void MyModelAnimationBone::setAnimationFrames(
	vector<MyModelAnimationBoneData *> *animationFrames) {
	this->animationFrames = animationFrames;
}

/*
*	Getter - Member variable "numAnimationFrames".
*	<p>
*	This function is the getter for current MyModelAnimationBone object's
*		member variable "numAnimationFrames".
*		- Number of animation frame data stored in the main data structure 
*		  "animationFrames".
*	@return		Return current MyModelAnimationBone object's
*					member variable "numAnimationFrames"
*					integer value.
*	@see		std::vector
*	@since		ver0041
*/
int MyModelAnimationBone::getNumAnimationFrames() {
	return this->animationFrames->size();
}

//==============================================================================
// Main data structure operations related.
//==============================================================================
/*
*	Insert the animation frame data, MyModelAnimationBoneData object passed in 
*	as parameter to the main data structure "animationFrames".
*	<p>
*	This function inserts the MyModelAnimationBoneData object animation frame 
*		data to current MyModelAnimationBone object's main std::vector type 
*		data structure  "animationFrames".
*	@param		animationFrameToInsert		MyModelAnimationBoneData pointer 
*											to insert with.
*	@return		void
*	@see		std::vector::push_back()
*	@since		ver0041
*/
void MyModelAnimationBone::insertAnimationFrameData(
	MyModelAnimationBoneData *animationFrameToInsert) {
	// Insert the new animation frame data MyModelAnimationBoneData object into 
	// the main std::vector type data structure "animationFrames".
	this->animationFrames->push_back(animationFrameToInsert);
}

/*
*	Remove all the animation frame data exist in the main data
*		structure "animationFrames".
*	<p>
*	This function removes all the animation frame data exist in the
*		main data structure "animationFrames", this can be done by calling the 
*		clear() function in std::vector.
*	@pre		The template classs Queue has deuque function implemented 
*					properly.
*	@return		void
*	@see		std::vector::clear()
*	@since		ver0041
*/
void MyModelAnimationBone::removeAllAnimationFrameData() {
	this->animationFrames->clear();
}

/*
*	Get MyModelAnimationBoneData pointer valid on given index inside the main
*		data structure "animationFrames".
*	<p>
*	This function retrieves the MyModelAnimationBoneData pointer on given
*		index inside the main data strcuture "animationFrames", this can be 
*		done by calling the at() function in std::vector.
*	@return		MyModelAnimationBoneData pointer found on given index if exist,
*					else return NULL.
*	@see		std::vector::at()
*	@since		ver0038
*/
MyModelAnimationBoneData *MyModelAnimationBone::getAnimationFrameAtIndex(
	int index) {
	return this->animationFrames->at(index);
}

