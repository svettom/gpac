/*
 *			GPAC - Multimedia Framework C SDK
 *
 *			Copyright (c) Jean Le Feuvre 2000-2005 
 *					All rights reserved
 *
 *  This file is part of GPAC / ISO Media File Format sub-project
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *   
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *   
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 */

#ifndef _GF_ISOMEDIA_DEV_H_
#define _GF_ISOMEDIA_DEV_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gpac/isomedia.h>


//the default size is 64, cause we need to handle large boxes...
#define GF_ISOM_BOX			\
	u32 type;			\
	u8 uuid[16];			\
	u64 size;			\

#define GF_ISOM_FULL_BOX		\
	GF_ISOM_BOX			\
	u8 version;			\
	u32 flags;			\


typedef struct
{
	GF_ISOM_BOX
} GF_Box;

typedef struct
{
	GF_ISOM_FULL_BOX
} GF_FullBox;

/*constructor*/
GF_Box *gf_isom_box_new(u32 boxType);

GF_Err gf_isom_box_write(GF_Box *ptr, GF_BitStream *bs);
GF_Err gf_isom_box_read(GF_Box *ptr, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *ptr);
GF_Err gf_isom_box_size(GF_Box *ptr);

GF_Err gf_isom_parse_box(GF_Box **outBox, GF_BitStream *bs);
GF_Err gf_isom_read_box_list(GF_Box *s, GF_BitStream *bs, GF_Err (*add_box)(GF_Box *par, GF_Box *b));

GF_Err gf_isom_box_get_size(GF_Box *ptr);
GF_Err gf_isom_full_box_get_size(GF_Box *ptr);
GF_Err gf_isom_box_write_header(GF_Box *ptr, GF_BitStream *bs);
GF_Err gf_isom_full_box_read(GF_Box *ptr, GF_BitStream *bs);
GF_Err gf_isom_full_box_write(GF_Box *s, GF_BitStream *bs);
void gf_isom_full_box_init(GF_Box *ptr);
void gf_isom_box_array_del(GF_List *boxList);
GF_Err gf_isom_box_array_write(GF_Box *parent, GF_List *list, GF_BitStream *bs);
GF_Err gf_isom_box_array_size(GF_Box *parent, GF_List *list);


enum
{
	GF_ISOM_BOX_TYPE_CO64	= GF_FOUR_CHAR_INT( 'c', 'o', '6', '4' ),
	GF_ISOM_BOX_TYPE_STCO	= GF_FOUR_CHAR_INT( 's', 't', 'c', 'o' ),
	GF_ISOM_BOX_TYPE_CRHD	= GF_FOUR_CHAR_INT( 'c', 'r', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_CTTS	= GF_FOUR_CHAR_INT( 'c', 't', 't', 's' ),
	GF_ISOM_BOX_TYPE_CPRT	= GF_FOUR_CHAR_INT( 'c', 'p', 'r', 't' ),
	GF_ISOM_BOX_TYPE_CHPL	= GF_FOUR_CHAR_INT( 'c', 'h', 'p', 'l' ),
	GF_ISOM_BOX_TYPE_URL	= GF_FOUR_CHAR_INT( 'u', 'r', 'l', ' ' ),
	GF_ISOM_BOX_TYPE_URN	= GF_FOUR_CHAR_INT( 'u', 'r', 'n', ' ' ),
	GF_ISOM_BOX_TYPE_DINF	= GF_FOUR_CHAR_INT( 'd', 'i', 'n', 'f' ),
	GF_ISOM_BOX_TYPE_DREF	= GF_FOUR_CHAR_INT( 'd', 'r', 'e', 'f' ),
	GF_ISOM_BOX_TYPE_STDP	= GF_FOUR_CHAR_INT( 's', 't', 'd', 'p' ),
	GF_ISOM_BOX_TYPE_EDTS	= GF_FOUR_CHAR_INT( 'e', 'd', 't', 's' ),
	GF_ISOM_BOX_TYPE_ELST	= GF_FOUR_CHAR_INT( 'e', 'l', 's', 't' ),
	GF_ISOM_BOX_TYPE_UUID	= GF_FOUR_CHAR_INT( 'u', 'u', 'i', 'd' ),
	GF_ISOM_BOX_TYPE_FREE	= GF_FOUR_CHAR_INT( 'f', 'r', 'e', 'e' ),
	GF_ISOM_BOX_TYPE_HDLR	= GF_FOUR_CHAR_INT( 'h', 'd', 'l', 'r' ),
	GF_ISOM_BOX_TYPE_HMHD	= GF_FOUR_CHAR_INT( 'h', 'm', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_HINT	= GF_FOUR_CHAR_INT( 'h', 'i', 'n', 't' ),
	GF_ISOM_BOX_TYPE_MDIA	= GF_FOUR_CHAR_INT( 'm', 'd', 'i', 'a' ),
	GF_ISOM_BOX_TYPE_MDAT	= GF_FOUR_CHAR_INT( 'm', 'd', 'a', 't' ),
	GF_ISOM_BOX_TYPE_MDHD	= GF_FOUR_CHAR_INT( 'm', 'd', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_MINF	= GF_FOUR_CHAR_INT( 'm', 'i', 'n', 'f' ),
	GF_ISOM_BOX_TYPE_MOOV	= GF_FOUR_CHAR_INT( 'm', 'o', 'o', 'v' ),
	GF_ISOM_BOX_TYPE_MVHD	= GF_FOUR_CHAR_INT( 'm', 'v', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_STSD	= GF_FOUR_CHAR_INT( 's', 't', 's', 'd' ),
	GF_ISOM_BOX_TYPE_STSZ	= GF_FOUR_CHAR_INT( 's', 't', 's', 'z' ),
	GF_ISOM_BOX_TYPE_STZ2	= GF_FOUR_CHAR_INT( 's', 't', 'z', '2' ),
	GF_ISOM_BOX_TYPE_STBL	= GF_FOUR_CHAR_INT( 's', 't', 'b', 'l' ),
	GF_ISOM_BOX_TYPE_STSC	= GF_FOUR_CHAR_INT( 's', 't', 's', 'c' ),
	GF_ISOM_BOX_TYPE_STSH	= GF_FOUR_CHAR_INT( 's', 't', 's', 'h' ),
	GF_ISOM_BOX_TYPE_SKIP	= GF_FOUR_CHAR_INT( 's', 'k', 'i', 'p' ),
	GF_ISOM_BOX_TYPE_SMHD	= GF_FOUR_CHAR_INT( 's', 'm', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_STSS	= GF_FOUR_CHAR_INT( 's', 't', 's', 's' ),
	GF_ISOM_BOX_TYPE_STTS	= GF_FOUR_CHAR_INT( 's', 't', 't', 's' ),
	GF_ISOM_BOX_TYPE_TRAK	= GF_FOUR_CHAR_INT( 't', 'r', 'a', 'k' ),
	GF_ISOM_BOX_TYPE_TKHD	= GF_FOUR_CHAR_INT( 't', 'k', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_TREF	= GF_FOUR_CHAR_INT( 't', 'r', 'e', 'f' ),
	GF_ISOM_BOX_TYPE_UDTA	= GF_FOUR_CHAR_INT( 'u', 'd', 't', 'a' ),
	GF_ISOM_BOX_TYPE_VMHD	= GF_FOUR_CHAR_INT( 'v', 'm', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_FTYP	= GF_FOUR_CHAR_INT( 'f', 't', 'y', 'p' ),
	GF_ISOM_BOX_TYPE_FADB	= GF_FOUR_CHAR_INT( 'p', 'a', 'd', 'b' ),
	GF_ISOM_BOX_TYPE_PDIN	= GF_FOUR_CHAR_INT( 'p', 'd', 'i', 'n' ),

#ifndef	GF_ISOM_NO_FRAGMENTS
	/*Movie Fragments*/
	GF_ISOM_BOX_TYPE_MVEX	= GF_FOUR_CHAR_INT( 'm', 'v', 'e', 'x' ),
	GF_ISOM_BOX_TYPE_MEHD	= GF_FOUR_CHAR_INT( 'm', 'e', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_TREX	= GF_FOUR_CHAR_INT( 't', 'r', 'e', 'x' ),
	GF_ISOM_BOX_TYPE_MOOF	= GF_FOUR_CHAR_INT( 'm', 'o', 'o', 'f' ),
	GF_ISOM_BOX_TYPE_MFHD	= GF_FOUR_CHAR_INT( 'm', 'f', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_TRAF	= GF_FOUR_CHAR_INT( 't', 'r', 'a', 'f' ),
	GF_ISOM_BOX_TYPE_TFHD	= GF_FOUR_CHAR_INT( 't', 'f', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_TRUN	= GF_FOUR_CHAR_INT( 't', 'r', 'u', 'n' ),
#endif

	/*MP4 extensions*/
	GF_ISOM_BOX_TYPE_DPND	= GF_FOUR_CHAR_INT( 'd', 'p', 'n', 'd' ),
	GF_ISOM_BOX_TYPE_IODS	= GF_FOUR_CHAR_INT( 'i', 'o', 'd', 's' ),
	GF_ISOM_BOX_TYPE_ESDS	= GF_FOUR_CHAR_INT( 'e', 's', 'd', 's' ),
	GF_ISOM_BOX_TYPE_MPOD	= GF_FOUR_CHAR_INT( 'm', 'p', 'o', 'd' ),
	GF_ISOM_BOX_TYPE_SYNC	= GF_FOUR_CHAR_INT( 's', 'y', 'n', 'c' ),
	GF_ISOM_BOX_TYPE_IPIR	= GF_FOUR_CHAR_INT( 'i', 'p', 'i', 'r' ),
	GF_ISOM_BOX_TYPE_SDHD	= GF_FOUR_CHAR_INT( 's', 'd', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_ODHD	= GF_FOUR_CHAR_INT( 'o', 'd', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_NMHD	= GF_FOUR_CHAR_INT( 'n', 'm', 'h', 'd' ),
	GF_ISOM_BOX_TYPE_MP4S	= GF_FOUR_CHAR_INT( 'm', 'p', '4', 's' ),
	GF_ISOM_BOX_TYPE_MP4A	= GF_FOUR_CHAR_INT( 'm', 'p', '4', 'a' ),
	GF_ISOM_BOX_TYPE_MP4V	= GF_FOUR_CHAR_INT( 'm', 'p', '4', 'v' ),

	/*AVC / H264 extension*/
	GF_ISOM_BOX_TYPE_AVCC	= GF_FOUR_CHAR_INT( 'a', 'v', 'c', 'C' ),
	GF_ISOM_BOX_TYPE_BTRT	= GF_FOUR_CHAR_INT( 'b', 't', 'r', 't' ),
	GF_ISOM_BOX_TYPE_M4DS	= GF_FOUR_CHAR_INT( 'm', '4', 'd', 's' ),
	GF_ISOM_BOX_TYPE_AVC1	= GF_FOUR_CHAR_INT( 'a', 'v', 'c', '1' ),

	/*3GPP extensions*/
	GF_ISOM_BOX_TYPE_DAMR	= GF_FOUR_CHAR_INT( 'd', 'a', 'm', 'r' ),
	GF_ISOM_BOX_TYPE_D263	= GF_FOUR_CHAR_INT( 'd', '2', '6', '3' ),
	GF_ISOM_BOX_TYPE_DEVC	= GF_FOUR_CHAR_INT( 'd', 'e', 'v', 'c' ),
	GF_ISOM_BOX_TYPE_DQCP	= GF_FOUR_CHAR_INT( 'd', 'q', 'c', 'p' ),
	GF_ISOM_BOX_TYPE_DSMV	= GF_FOUR_CHAR_INT( 'd', 's', 'm', 'v' ),

	/*3GPP text / MPEG-4 StreamingText*/
	GF_ISOM_BOX_TYPE_FTAB	= GF_FOUR_CHAR_INT( 'f', 't', 'a', 'b' ),
	GF_ISOM_BOX_TYPE_TX3G	= GF_FOUR_CHAR_INT( 't', 'x', '3', 'g' ),
	GF_ISOM_BOX_TYPE_STYL	= GF_FOUR_CHAR_INT( 's', 't', 'y', 'l' ),
	GF_ISOM_BOX_TYPE_HLIT	= GF_FOUR_CHAR_INT( 'h', 'l', 'i', 't' ),
	GF_ISOM_BOX_TYPE_HCLR	= GF_FOUR_CHAR_INT( 'h', 'c', 'l', 'r' ),
	GF_ISOM_BOX_TYPE_KROK	= GF_FOUR_CHAR_INT( 'k', 'r', 'o', 'k' ),
	GF_ISOM_BOX_TYPE_DLAY	= GF_FOUR_CHAR_INT( 'd', 'l', 'a', 'y' ),
	GF_ISOM_BOX_TYPE_HREF	= GF_FOUR_CHAR_INT( 'h', 'r', 'e', 'f' ),
	GF_ISOM_BOX_TYPE_TBOX	= GF_FOUR_CHAR_INT( 't', 'b', 'o', 'x' ),
	GF_ISOM_BOX_TYPE_BLNK	= GF_FOUR_CHAR_INT( 'b', 'l', 'n', 'k' ),
	GF_ISOM_BOX_TYPE_TWRP	= GF_FOUR_CHAR_INT( 't', 'w', 'r', 'p' ),

	/* ISO Base Media File Format Extensions for MPEG-21 */
	GF_ISOM_BOX_TYPE_META	= GF_FOUR_CHAR_INT( 'm', 'e', 't', 'a' ),
	GF_ISOM_BOX_TYPE_XML	= GF_FOUR_CHAR_INT( 'x', 'm', 'l', ' ' ),
	GF_ISOM_BOX_TYPE_BXML	= GF_FOUR_CHAR_INT( 'b', 'x', 'm', 'l' ),
	GF_ISOM_BOX_TYPE_ILOC	= GF_FOUR_CHAR_INT( 'i', 'l', 'o', 'c' ),
	GF_ISOM_BOX_TYPE_PITM	= GF_FOUR_CHAR_INT( 'p', 'i', 't', 'm' ),
	GF_ISOM_BOX_TYPE_IPRO	= GF_FOUR_CHAR_INT( 'i', 'p', 'r', 'o' ),
	GF_ISOM_BOX_TYPE_INFE	= GF_FOUR_CHAR_INT( 'i', 'n', 'f', 'e' ),
	GF_ISOM_BOX_TYPE_IINF	= GF_FOUR_CHAR_INT( 'i', 'i', 'n', 'f' ),
	GF_ISOM_BOX_TYPE_IMIF	= GF_FOUR_CHAR_INT( 'i', 'm', 'i', 'f' ),
	GF_ISOM_BOX_TYPE_IPMC	= GF_FOUR_CHAR_INT( 'i', 'p', 'm', 'c' ),
	GF_ISOM_BOX_TYPE_ENCA	= GF_FOUR_CHAR_INT( 'e', 'n', 'c', 'a' ),
	GF_ISOM_BOX_TYPE_ENCV	= GF_FOUR_CHAR_INT( 'e', 'n', 'c', 'v' ),
	GF_ISOM_BOX_TYPE_ENCT	= GF_FOUR_CHAR_INT( 'e', 'n', 'c', 't' ),
	GF_ISOM_BOX_TYPE_ENCS	= GF_FOUR_CHAR_INT( 'e', 'n', 'c', 's' ),
	GF_ISOM_BOX_TYPE_SINF	= GF_FOUR_CHAR_INT( 's', 'i', 'n', 'f' ),
	GF_ISOM_BOX_TYPE_FRMA	= GF_FOUR_CHAR_INT( 'f', 'r', 'm', 'a' ),
	GF_ISOM_BOX_TYPE_SCHM	= GF_FOUR_CHAR_INT( 's', 'c', 'h', 'm' ),
	GF_ISOM_BOX_TYPE_SCHI	= GF_FOUR_CHAR_INT( 's', 'c', 'h', 'i' ),

	/* ISMA 1.0 Encryption and Authentication V 1.0 */
	GF_ISOM_BOX_TYPE_IKMS	= GF_FOUR_CHAR_INT( 'i', 'K', 'M', 'S' ),
	GF_ISOM_BOX_TYPE_ISFM	= GF_FOUR_CHAR_INT( 'i', 'S', 'F', 'M' ),

	/* Hinting boxes */
	GF_ISOM_BOX_TYPE_RTP_STSD	= GF_FOUR_CHAR_INT( 'r', 't', 'p', ' ' ),
	GF_ISOM_BOX_TYPE_HNTI	= GF_FOUR_CHAR_INT( 'h', 'n', 't', 'i' ),
	GF_ISOM_BOX_TYPE_RTP	= GF_FOUR_CHAR_INT( 'r', 't', 'p', ' ' ),
	GF_ISOM_BOX_TYPE_SDP	= GF_FOUR_CHAR_INT( 's', 'd', 'p', ' ' ),
	GF_ISOM_BOX_TYPE_HINF	= GF_FOUR_CHAR_INT( 'h', 'i', 'n', 'f' ),
	GF_ISOM_BOX_TYPE_NAME	= GF_FOUR_CHAR_INT( 'n', 'a', 'm', 'e' ),
	GF_ISOM_BOX_TYPE_TRPY	= GF_FOUR_CHAR_INT( 't', 'r', 'p', 'y' ),
	GF_ISOM_BOX_TYPE_NUMP	= GF_FOUR_CHAR_INT( 'n', 'u', 'm', 'p' ),
	GF_ISOM_BOX_TYPE_TOTL	= GF_FOUR_CHAR_INT( 't', 'o', 't', 'l' ),
	GF_ISOM_BOX_TYPE_NPCK	= GF_FOUR_CHAR_INT( 'n', 'p', 'c', 'k' ),
	GF_ISOM_BOX_TYPE_TPYL	= GF_FOUR_CHAR_INT( 't', 'p', 'y', 'l' ),
	GF_ISOM_BOX_TYPE_TPAY	= GF_FOUR_CHAR_INT( 't', 'p', 'a', 'y' ),
	GF_ISOM_BOX_TYPE_MAXR	= GF_FOUR_CHAR_INT( 'm', 'a', 'x', 'r' ),
	GF_ISOM_BOX_TYPE_DMED	= GF_FOUR_CHAR_INT( 'd', 'm', 'e', 'd' ),
	GF_ISOM_BOX_TYPE_DIMM	= GF_FOUR_CHAR_INT( 'd', 'i', 'm', 'm' ),
	GF_ISOM_BOX_TYPE_DREP	= GF_FOUR_CHAR_INT( 'd', 'r', 'e', 'p' ),
	GF_ISOM_BOX_TYPE_TMIN	= GF_FOUR_CHAR_INT( 't', 'm', 'i', 'n' ),
	GF_ISOM_BOX_TYPE_TMAX	= GF_FOUR_CHAR_INT( 't', 'm', 'a', 'x' ),
	GF_ISOM_BOX_TYPE_PMAX	= GF_FOUR_CHAR_INT( 'p', 'm', 'a', 'x' ),
	GF_ISOM_BOX_TYPE_DMAX	= GF_FOUR_CHAR_INT( 'd', 'm', 'a', 'x' ),
	GF_ISOM_BOX_TYPE_PAYT	= GF_FOUR_CHAR_INT( 'p', 'a', 'y', 't' ),
	GF_ISOM_BOX_TYPE_RELY	= GF_FOUR_CHAR_INT( 'r', 'e', 'l', 'y' ),
	GF_ISOM_BOX_TYPE_TIMS	= GF_FOUR_CHAR_INT( 't', 'i', 'm', 's' ),
	GF_ISOM_BOX_TYPE_TSRO	= GF_FOUR_CHAR_INT( 't', 's', 'r', 'o' ),
	GF_ISOM_BOX_TYPE_SNRO	= GF_FOUR_CHAR_INT( 's', 'n', 'r', 'o' ),
	GF_ISOM_BOX_TYPE_RTPO	= GF_FOUR_CHAR_INT( 'r', 't', 'p', 'o' ),
	
	/*ALL INTERNAL BOXES - NEVER WRITTEN TO FILE!!*/

	/*generic handlers*/
	GF_ISOM_BOX_TYPE_GNRM	= GF_FOUR_CHAR_INT( 'g', 'n', 'r', 'm' ),
	GF_ISOM_BOX_TYPE_GNRV	= GF_FOUR_CHAR_INT( 'g', 'n', 'r', 'v' ),
	GF_ISOM_BOX_TYPE_GNRA	= GF_FOUR_CHAR_INT( 'g', 'n', 'r', 'a' ),
	/*storage of AU fragments (for MPEG-4 visual resync marker (video packets), located in stbl.*/
	GF_ISOM_BOX_TYPE_STSF	=  GF_FOUR_CHAR_INT( 'S', 'T', 'S', 'F' ),
	/*base constructor of all hint formats (currently only RTP uses it)*/
	GF_ISOM_BOX_TYPE_GHNT	= GF_FOUR_CHAR_INT( 'g', 'h', 'n', 't' ),
	/*for compatibility with old files hinted for DSS - needs special parsing*/
	GF_ISOM_BOX_TYPE_VOID	= GF_FOUR_CHAR_INT( 'V', 'O', 'I', 'D' ),
};


typedef struct
{
	GF_ISOM_BOX
	/*note: the data is NEVER loaded to the mdat in this lib*/
	u64 dataSize;
	char *data;
} GF_MediaDataBox;

typedef struct
{
	GF_ISOM_BOX
	char *data;
	u32 dataSize;
} GF_UnknownBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u64 creationTime;
	u64 modificationTime;
	u32 timeScale;
	u64 duration;
	u32 nextTrackID;
	u32 preferredRate;
	u16 preferredVolume;
	char reserved[10];
	u32 matrixA;
	u32 matrixB;
	u32 matrixU;
	u32 matrixC;
	u32 matrixD;
	u32 matrixV;
	u32 matrixW;
	u32 matrixX;
	u32 matrixY;
	u32 previewTime;
	u32 previewDuration;
	u32 posterTime;
	u32 selectionTime;
	u32 selectionDuration;
	u32 currentTime;
} GF_MovieHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_Descriptor *descriptor;
} GF_ObjectDescriptorBox;

/*used for entry list*/
typedef struct
{
	u64 segmentDuration;
	s64 mediaTime;
	u32 mediaRate;
} GF_EdtsEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entryList;
} GF_EditListBox;

typedef struct
{
	GF_ISOM_BOX
	GF_EditListBox *editList;
} GF_EditBox;


/*used to classify boxes in the UserData GF_Box*/
typedef struct
{
	u32 boxType;
	u8 uuid[16];
	GF_List *boxList;
} GF_UserDataMap;

typedef struct
{
	GF_ISOM_BOX
	GF_List *recordList;
} GF_UserDataBox;

typedef struct
{
	GF_ISOM_BOX
	GF_MovieHeaderBox *mvhd;
	GF_ObjectDescriptorBox *iods;
	GF_UserDataBox *udta;
#ifndef	GF_ISOM_NO_FRAGMENTS
	struct __tag_mvex_box *mvex;
#endif
	/*meta box if any*/
	struct __tag_meta_box *meta;
	/*track boxes*/
	GF_List *trackList;

	GF_ISOFile *mov;

} GF_MovieBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u64 creationTime;
	u64 modificationTime;
	u32 trackID;
	u32 reserved1;
	u64 duration;
	u32 reserved2[2];
	u16 layer;
	u16 alternate_group;
	u16 volume;
	u16 reserved3;
	u32 matrix[9];
	u32 width, height;
} GF_TrackHeaderBox;

typedef struct
{
	GF_ISOM_BOX
	GF_List *boxList;
} GF_TrackReferenceBox;



typedef struct
{
	GF_ISOM_BOX
	GF_UserDataBox *udta;
	GF_TrackHeaderBox *Header;
	struct __tag_media_box *Media;
	GF_EditBox *editBox;
	GF_TrackReferenceBox *References;
	/*meta box if any*/
	struct __tag_meta_box *meta;

	GF_MovieBox *moov;
	/*private for media padding*/
	u32 padding_bytes;
	/*private for editing*/
	char *name;
	/*private for editing*/
	Bool is_unpacked;
} GF_TrackBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u64 creationTime;
	u64 modificationTime;
	u32 timeScale;
	u64 duration;
	char packedLanguage[4];
	u16 reserved;
} GF_MediaHeaderBox;


typedef struct
{
	GF_ISOM_FULL_BOX
	u32 reserved1;
	u32 handlerType;
	u8 reserved2[12];
	u32 nameLength;
	char *nameUTF8;
} GF_HandlerBox;

typedef struct __tag_media_box
{
	GF_ISOM_BOX
	GF_TrackBox *mediaTrack;
	GF_MediaHeaderBox *mediaHeader;
	GF_HandlerBox *handler;
	struct __tag_media_info_box *information;
	u64 BytesMissing;
} GF_MediaBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u64 reserved;
} GF_VideoMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 reserved;
} GF_SoundMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	/*this is used for us INTERNALLY*/
	u32 subType;
	u32 maxPDUSize;
	u32 avgPDUSize;
	u32 maxBitrate;
	u32 avgBitrate;
	u32 slidingAverageBitrate;
} GF_HintMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
} GF_MPEGMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
} GF_ODMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
} GF_OCRMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
} GF_SceneMediaHeaderBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *boxList;
} GF_DataReferenceBox;

typedef struct
{
	GF_ISOM_BOX
	GF_DataReferenceBox *dref;
} GF_DataInformationBox;

#define GF_ISOM_DATAENTRY_FIELDS	\
	char *location;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_ISOM_DATAENTRY_FIELDS
} GF_DataEntryBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_ISOM_DATAENTRY_FIELDS
} GF_DataEntryURLBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_ISOM_DATAENTRY_FIELDS
	char *nameURN;
} GF_DataEntryURNBox;

typedef struct
{
	u32 sampleCount;
	u32 sampleDelta;
} GF_SttsEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entryList;
#ifndef GPAC_READ_ONLY
	/*cache for WRITE*/
	GF_SttsEntry *w_currentEntry;
	u32 w_currentSampleNum;
	u32 w_LastDTS;
#endif
	/*cache for READ*/
	u32 r_FirstSampleInEntry;
	u32 r_currentEntryIndex;
	u32 r_CurrentDTS;
} GF_TimeToSampleBox;

typedef struct
{
	u32 sampleCount;
	u32 decodingOffset;
} GF_DttsEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entryList;
#ifndef GPAC_READ_ONLY
	/*Cache for write*/
	GF_DttsEntry *w_currentEntry;
	u32 w_LastSampleNumber;
	/*force one sample per entry*/
	Bool unpack_mode;
#endif
	/*Cache for read*/
	u32 r_currentEntryIndex;
	u32 r_FirstSampleInEntry;
} GF_CompositionOffsetBox;


typedef struct
{
	u32 SampleNumber;
	u32 fragmentCount;
	u16 *fragmentSizes;
} GF_StsfEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entryList;
#ifndef GPAC_READ_ONLY
	/*Cache for write*/
	GF_StsfEntry *w_currentEntry;
	u32 w_currentEntryIndex;
#endif
	/*Cache for read*/
	u32 r_currentEntryIndex;
	GF_StsfEntry *r_currentEntry;
} GF_SampleFragmentBox;


#define GF_ISOM_SAMPLE_ENTRY_FIELDS		\
	u16 dataReferenceIndex;	\
	char reserved[ 6 ]; \
	struct __tag_protect_box *protection_info;

/*base sample entry box (never used but for typecasting)*/
typedef struct
{
	GF_ISOM_BOX
	GF_ISOM_SAMPLE_ENTRY_FIELDS
} GF_SampleEntryBox;

typedef struct
{
	GF_ISOM_BOX
	GF_ISOM_SAMPLE_ENTRY_FIELDS
	/*box type as specified in the file (not this box's type!!)*/
	u32 EntryType;

	char *data;
	u32 data_size;
} GF_GenericSampleEntryBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_ESD *desc;
} GF_ESDBox;

/*for all MPEG4 media except audio and video*/
typedef struct
{
	GF_ISOM_BOX
	GF_ISOM_SAMPLE_ENTRY_FIELDS
	GF_ESDBox *esd;
	/*used for hinting when extracting the OD stream...*/
	GF_SLConfig *slc;
} GF_MPEGSampleEntryBox;


#define GF_ISOM_VISUAL_SAMPLE_ENTRY		\
	GF_ISOM_BOX							\
	GF_ISOM_SAMPLE_ENTRY_FIELDS					\
	u16 version;						\
	u16 revision;						\
	u32 vendor;							\
	u32 temporal_quality;				\
	u32 spacial_quality;				\
	u16 Width, Height;					\
	u32 horiz_res, vert_res;			\
	u32 entry_data_size;				\
	u16 frames_per_sample;				\
	unsigned char compressor_name[33];	\
	u16 bit_depth;						\
	s16 color_table_index;

typedef struct
{
	GF_ISOM_VISUAL_SAMPLE_ENTRY
} GF_VisualSampleEntryBox;

void gf_isom_video_sample_entry_init(GF_VisualSampleEntryBox *ent);
GF_Err gf_isom_video_sample_entry_read(GF_VisualSampleEntryBox *ptr, GF_BitStream *bs);
#ifndef GPAC_READ_ONLY
void gf_isom_video_sample_entry_write(GF_VisualSampleEntryBox *ent, GF_BitStream *bs);
void gf_isom_video_sample_entry_size(GF_VisualSampleEntryBox *ent);
#endif


typedef struct
{
	GF_ISOM_VISUAL_SAMPLE_ENTRY
	GF_ESDBox *esd;
	GF_SLConfig *slc;
} GF_MPEGVisualSampleEntryBox;


/*this is the default visual sdst (to handle unknown media)*/
typedef struct
{
	GF_ISOM_VISUAL_SAMPLE_ENTRY
	/*box type as specified in the file (not this box's type!!)*/
	u32 EntryType;
	/*opaque description data (ESDS in MP4, SMI in SVQ3, ...)*/
	char *data;
	u32 data_size;
} GF_GenericVisualSampleEntryBox;


typedef struct
{
	GF_ISOM_BOX
	u32 bufferSizeDB;
	u32 maxBitrate;
	u32 avgBitrate;
} GF_MPEG4BitRateBox;

typedef struct
{
	GF_ISOM_BOX
	GF_List *descriptors;
} GF_MPEG4ExtensionDescriptorsBox;

typedef struct
{
	GF_ISOM_BOX
	GF_AVCConfig *config;
} GF_AVCConfigurationBox;

typedef struct
{
	GF_ISOM_VISUAL_SAMPLE_ENTRY

	GF_AVCConfigurationBox *avc_config;
	GF_MPEG4BitRateBox *bitrate;
	/*ext descriptors*/
	GF_MPEG4ExtensionDescriptorsBox *descr;
	/*used for Publishing*/
	GF_SLConfig *slc;
	/*internally emulated esd*/
	GF_ESD *esd;
} GF_AVCSampleEntryBox;


#define GF_ISOM_AUDIO_SAMPLE_ENTRY		\
	GF_ISOM_BOX						\
	GF_ISOM_SAMPLE_ENTRY_FIELDS				\
	u16 version;					\
	u16 revision;					\
	u32 vendor;						\
	u16 channel_count;				\
	u16 bitspersample;				\
	u16 compression_id;				\
	u16 packet_size;				\
	u16 samplerate_hi;				\
	u16 samplerate_lo;

typedef struct 
{
	GF_ISOM_AUDIO_SAMPLE_ENTRY
} GF_AudioSampleEntryBox;

void gf_isom_audio_sample_entry_init(GF_AudioSampleEntryBox *ptr);
GF_Err gf_isom_audio_sample_entry_read(GF_AudioSampleEntryBox *ptr, GF_BitStream *bs);
#ifndef GPAC_READ_ONLY
void gf_isom_audio_sample_entry_write(GF_AudioSampleEntryBox *ptr, GF_BitStream *bs);
void gf_isom_audio_sample_entry_size(GF_AudioSampleEntryBox *ptr);
#endif


typedef struct
{
	GF_ISOM_AUDIO_SAMPLE_ENTRY
	GF_ESDBox *esd;
	GF_SLConfig *slc;
} GF_MPEGAudioSampleEntryBox;

typedef struct
{
	GF_ISOM_BOX
	GF_3GPConfig cfg;
} GF_3GPPConfigBox;

typedef struct
{
	GF_ISOM_AUDIO_SAMPLE_ENTRY
	GF_3GPPConfigBox *info;
} GF_3GPPAudioSampleEntryBox;

typedef struct
{
	GF_ISOM_VISUAL_SAMPLE_ENTRY
	GF_3GPPConfigBox *info;
} GF_3GPPVisualSampleEntryBox;

/*this is the default visual sdst (to handle unknown media)*/
typedef struct
{
	GF_ISOM_AUDIO_SAMPLE_ENTRY
	/*box type as specified in the file (not this box's type!!)*/
	u32 EntryType;
	/*opaque description data (ESDS in MP4, ...)*/
	char *data;
	u32 data_size;
} GF_GenericAudioSampleEntryBox;


typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *boxList;
} GF_SampleDescriptionBox;


typedef struct
{
	GF_ISOM_FULL_BOX
	/*if this is the compact version, sample size is actually fieldSize*/
	u32 sampleSize;
	u32 sampleCount;
 	u32 alloc_size;
	u32 *sizes;
} GF_SampleSizeBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 entryCount;
	u32 alloc_size;
	u32 *offsets;
} GF_ChunkOffsetBox;

typedef struct 
{
	GF_ISOM_FULL_BOX
	u32 entryCount;
	u32 alloc_size;
	u64 *offsets;
} GF_ChunkLargeOffsetBox;

typedef struct
{
	u32 firstChunk;
	u32 nextChunk;
	u32 samplesPerChunk;
	u32 sampleDescriptionIndex;
	u8 isEdited;
} GF_StscEntry;


typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entryList;
	GF_StscEntry *currentEntry;
	/*0-based cache for READ. In WRITE mode, we always have 1 sample per chunk so no need for a cache*/
	u32 currentIndex;
	/*first sample number in this chunk*/
	u32 firstSampleInCurrentChunk;
	u32 currentChunk;
	u32 ghostNumber;
} GF_SampleToChunkBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 entryCount;
	u32 *sampleNumbers;
	/*cache for READ mode (in write we realloc no matter what)*/
	u32 r_LastSyncSample;
	/*0-based index in the array*/
	u32 r_LastSampleIndex;
} GF_SyncSampleBox;

typedef struct
{
	u32 shadowedSampleNumber;
	s32 syncSampleNumber;
} GF_StshEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *entries;
	/*Cache for read mode*/
	u32 r_LastEntryIndex;
	u32 r_LastFoundSample;
} GF_ShadowSyncBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 entryCount;
	u16 *priorities;
} GF_DegradationPriorityBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 SampleCount;
	u8 *padbits;
} GF_PaddingBitsBox;


typedef struct
{
	GF_ISOM_BOX
	GF_TimeToSampleBox *TimeToSample;
	GF_CompositionOffsetBox *CompositionOffset;
	GF_SyncSampleBox *SyncSample;
	GF_SampleDescriptionBox *SampleDescription;
	GF_SampleSizeBox *SampleSize;
	GF_SampleToChunkBox *SampleToChunk;
	/*untyped, to handle 32 bits and 64 bits chunkOffsets*/
	GF_Box *ChunkOffset;
	GF_ShadowSyncBox *ShadowSync;
	GF_DegradationPriorityBox *DegradationPriority;
	GF_PaddingBitsBox *PaddingBits;
	GF_SampleFragmentBox *Fragments;

	u32 MaxSamplePerChunk;
	u16 groupID;
	u16 trackPriority;
	u32 currentEntryIndex;
} GF_SampleTableBox;

typedef struct __tag_media_info_box
{
	GF_ISOM_BOX
	GF_DataInformationBox *dataInformation;
	GF_SampleTableBox *sampleTable;
	GF_Box *InfoHeader;
	struct __tag_data_map *dataHandler;
	u32 dataEntryIndex;
} GF_MediaInformationBox;


typedef struct
{
	GF_ISOM_BOX
	char *data;
	u32 dataSize;
} GF_FreeSpaceBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	char packedLanguageCode[4];
	char *notice;
} GF_CopyrightBox;


typedef struct
{
	char *name;
	u64 start_time;
} GF_ChapterEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *list;
} GF_ChapterListBox;

#define GF_WatermarkBox GF_UnknownBox

typedef struct
{
	GF_ISOM_BOX
	u32 trackIDCount;
	u32 *trackIDs;
} GF_TrackReferenceTypeBox;

typedef struct
{
	GF_ISOM_BOX
	u32 majorBrand;
	u32 minorVersion;
	u32 altCount;
	u32 *altBrand;
} GF_FileTypeBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 *rates;
	u32 *times;
	u32 count;
} GF_ProgressiveDownloadBox;


/*
	3GPP streaming text boxes
*/

typedef struct
{
	GF_ISOM_BOX
	u32 entry_count;
	GF_FontRecord *fonts;
} GF_FontTableBox;

typedef struct
{
	GF_ISOM_BOX						\
	GF_ISOM_SAMPLE_ENTRY_FIELDS				\
	u32 displayFlags;
	s8 horizontal_justification;
	s8 vertical_justification;
	/*ARGB*/
	u32 back_color;
	GF_BoxRecord default_box; 
	GF_StyleRecord	default_style;
	GF_FontTableBox *font_table;
} GF_TextSampleEntryBox;

typedef struct
{
	GF_ISOM_BOX
	u32 entry_count;
	GF_StyleRecord *styles;
} GF_TextStyleBox;

typedef struct
{
	GF_ISOM_BOX
	u16 startcharoffset;
	u16 endcharoffset; 
} GF_TextHighlightBox;

typedef struct
{
	GF_ISOM_BOX
	/*ARGB*/
	u32 hil_color;
} GF_TextHighlightColorBox;

typedef struct
{
	u32 highlight_endtime;
	u16 start_charoffset;
	u16 end_charoffset;
} KaraokeRecord;

typedef struct
{
	GF_ISOM_BOX
	u32 highlight_starttime;
	u16 entrycount;
	KaraokeRecord *records;
} GF_TextKaraokeBox;

typedef struct
{
	GF_ISOM_BOX
	u32 scroll_delay;
} GF_TextScrollDelayBox;

typedef struct
{
	GF_ISOM_BOX
	u16 startcharoffset;
	u16 endcharoffset;
	char *URL;
	char *URL_hint;
} GF_TextHyperTextBox;

typedef struct
{
	GF_ISOM_BOX
	GF_BoxRecord box;
} GF_TextBoxBox;

typedef struct
{
	GF_ISOM_BOX
	u16 startcharoffset;
	u16 endcharoffset;
} GF_TextBlinkBox;

typedef struct
{
	GF_ISOM_BOX
	u8 wrap_flag;
} GF_TextWrapBox;

/*
	MPEG-21 extensions
*/
typedef struct
{
	GF_ISOM_FULL_BOX
	u32 xml_length;
	u8 *xml;
} GF_XMLBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 data_length;
	u8 *data;
} GF_BinaryXMLBox;

typedef struct
{
	u64 extent_offset;
	u64 extent_length;
#ifndef GPAC_READ_OLNLY
	/*for storage only*/
	u64 original_extent_offset;
#endif
} GF_ItemExtentEntry;

typedef struct 
{
	u16 item_ID;
	u16 data_reference_index;
	u64 base_offset;
#ifndef GPAC_READ_OLNLY
	/*for storage only*/
	u64 original_base_offset;
#endif
	GF_List *extent_entries;
} GF_ItemLocationEntry;

typedef struct
{
	GF_ISOM_FULL_BOX
	u8 offset_size;
    u8 length_size;
	u8 base_offset_size;
	GF_List *location_entries;
} GF_ItemLocationBox;

typedef	struct 
{
	GF_ISOM_FULL_BOX
	u16 item_ID;
} GF_PrimaryItemBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *protection_information;
} GF_ItemProtectionBox;

typedef struct 
{
	GF_ISOM_FULL_BOX
	u16 item_ID;
	u16 item_protection_index;
	/*zero-terminated strings*/
	u8  *item_name;
	u8  *content_type;
	u8  *content_encoding;
	// needed to actually read the resource file, but not written in the MP21 file.
	u8  *full_path;
} GF_ItemInfoEntryBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *item_infos;
} GF_ItemInfoBox;

typedef struct
{
	GF_ISOM_BOX
	u32 data_format;
} GF_OriginalFormatBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 scheme_type;
	u32 scheme_version;
	char *URI;
} GF_SchemeTypeBox;

/*ISMACryp specific*/
typedef struct
{
	GF_ISOM_FULL_BOX
	/*zero-terminated string*/
	char *URI;
} GF_ISMAKMSBox;

/*ISMACryp specific*/
typedef struct
{
	GF_ISOM_FULL_BOX
	u8 selective_encryption;
	u8 key_indicator_length;
	u8 IV_length;
} GF_ISMASampleFormatBox;

typedef struct
{
	GF_ISOM_BOX
	GF_ISMAKMSBox *ikms;
	GF_ISMASampleFormatBox *isfm;
} GF_SchemeInformationBox;

typedef struct __tag_protect_box
{
	GF_ISOM_BOX
	GF_OriginalFormatBox *original_format;
	GF_SchemeTypeBox *scheme_type;
	GF_SchemeInformationBox *info;
} GF_ProtectionInfoBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_List *descriptors;
} GF_IPMPInfoBox;

typedef struct
{
	GF_ISOM_FULL_BOX
	GF_IPMP_ToolList *ipmp_tools;
	GF_List *descriptors;
} GF_IPMPControlBox;


typedef struct __tag_meta_box
{
	GF_ISOM_FULL_BOX
	GF_HandlerBox *handler;	
	GF_PrimaryItemBox *primary_resource;
	GF_DataInformationBox *file_locations;
	GF_ItemLocationBox *item_locations;
	GF_ItemProtectionBox *protections;
	GF_ItemInfoBox *item_infos;
	GF_IPMPControlBox *IPMP_control;
	GF_List *other_boxes;
} GF_MetaBox;




#ifndef	GF_ISOM_NO_FRAGMENTS

/*V2 boxes - Movie Fragments*/

typedef struct
{
	GF_ISOM_FULL_BOX
	u64 fragment_duration;
} GF_MovieExtendsHeaderBox;


typedef struct __tag_mvex_box
{
	GF_ISOM_BOX
	GF_List *TrackExList;
	GF_MovieExtendsHeaderBox *mehd;
	GF_ISOFile *mov;
} GF_MovieExtendsBox;

/*the TrackExtends contains default values for the track fragments*/
typedef struct
{
	GF_ISOM_FULL_BOX
	u32 trackID;
	u32 def_sample_desc_index;
	u32 def_sample_duration;
	u32 def_sample_size;
	u32 def_sample_flags;
	GF_TrackBox *track;
} GF_TrackExtendsBox;

/*indicates the seq num of this fragment*/
typedef struct
{
	GF_ISOM_FULL_BOX
	u32 sequence_number;
} GF_MovieFragmentHeaderBox;

/*MovieFragment is a container IN THE FILE, contains 1 fragment*/
typedef struct
{
	GF_ISOM_BOX
	GF_MovieFragmentHeaderBox *mfhd;
	GF_List *TrackList;
	GF_ISOFile *mov;
} GF_MovieFragmentBox;


/*FLAGS for TRAF*/
enum
{
	GF_ISOM_TRAF_BASE_OFFSET	=	0x01,
	GF_ISOM_TRAF_SAMPLE_DESC	=	0x02,
	GF_ISOM_TRAF_SAMPLE_DUR	=	0x08,
	GF_ISOM_TRAF_SAMPLE_SIZE	=	0x10,
	GF_ISOM_TRAF_SAMPLE_FLAGS	=	0x20,
	GF_ISOM_TRAF_DUR_EMPTY	=	0x10000
};

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 trackID;
	/* all the following are optional fields */
	u64 base_data_offset;
	u32 sample_desc_index;
	u32 def_sample_duration;
	u32 def_sample_size;
	u32 def_sample_flags;
	u32 EmptyDuration;
	u8 IFrameSwitching;
} GF_TrackFragmentHeaderBox;

typedef struct
{
	GF_ISOM_BOX
	GF_TrackFragmentHeaderBox *tfhd;
	GF_List *TrackRuns;
	/*keep a pointer to default flags*/
	GF_TrackExtendsBox *trex;
	/*when data caching is on*/
	u32 DataCache;
} GF_TrackFragmentBox;

/*FLAGS for TRUN : specify what is written in the SampleTable of TRUN*/
enum
{
	GF_ISOM_TRUN_DATA_OFFSET	= 0x01,
	GF_ISOM_TRUN_FIRST_FLAG		= 0x04,
	GF_ISOM_TRUN_DURATION		= 0x100,
	GF_ISOM_TRUN_SIZE			= 0x200,
	GF_ISOM_TRUN_FLAGS			= 0x400,
	GF_ISOM_TRUN_CTS_OFFSET		= 0x800
};

typedef struct
{
	GF_ISOM_FULL_BOX
	u32 sample_count;
	/*the following are optional fields */
	s32 data_offset;
	u32 first_sample_flags;
	/*can be empty*/
	GF_List *entries;

	/*in write mode with data caching*/
	GF_BitStream *cache;
} GF_TrackFragmentRunBox;

typedef struct
{
	u32 Duration;
	u32 size;
	u32 flags;
	u32 CTS_Offset;
} GF_TrunEntry;

#endif


/*RTP Hint Track Sample Entry*/
typedef struct
{
	GF_ISOM_BOX
	GF_ISOM_SAMPLE_ENTRY_FIELDS
	u16 HintTrackVersion;
	u16 LastCompatibleVersion;
	u32 MaxPacketSize;
	GF_List *HintDataTable;
	/*this is where we store the current RTP sample in read/write mode*/
	struct __tag_hint_sample *hint_sample;
	/*current hint sample in read mode, 1-based (0 is reset)*/
	u32 cur_sample;
	u32 pck_sn, ts_offset, ssrc;
	GF_TrackReferenceTypeBox *hint_ref;
} GF_HintSampleEntryBox;


typedef struct
{
	GF_ISOM_BOX
	u32 subType;
	char *sdpText;
} GF_RTPBox;

typedef struct
{
	GF_ISOM_BOX
	char *sdpText;
} GF_SDPBox;

typedef struct
{
	GF_ISOM_BOX
	s32 timeOffset;
} GF_RTPOBox;

typedef struct
{
	GF_ISOM_BOX
	/*contains GF_SDPBox if in track, GF_RTPBox if in movie*/
	GF_Box *SDP;
	GF_List *boxList;
} GF_HintTrackInfoBox;

typedef struct
{
	GF_ISOM_BOX
	u8 reserved;
	u8 prefered;
	u8 required;
} GF_RelyHintBox;

/***********************************************************
			data entry tables for RTP
***********************************************************/
typedef struct
{
	GF_ISOM_BOX
	u32 timeScale;
} GF_TSHintEntryBox;

typedef struct
{
	GF_ISOM_BOX
	u32 TimeOffset;	
} GF_TimeOffHintEntryBox;

typedef struct
{
	GF_ISOM_BOX
	u32 SeqOffset;
} GF_SeqOffHintEntryBox;



/***********************************************************
			hint track information boxes for RTP
***********************************************************/

/*Total number of bytes that will be sent, including 12-byte RTP headers, but not including any network headers*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbBytes;
} GF_TRPYBox;

/*32-bits version of trpy used in Darwin*/
typedef struct
{
	GF_ISOM_BOX
	u32 nbBytes;
} GF_TOTLBox;

/*Total number of network packets that will be sent*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbPackets;
} GF_NUMPBox;

/*32-bits version of nump used in Darwin*/
typedef struct
{
	GF_ISOM_BOX
	u32 nbPackets;
} GF_NPCKBox;


/*Total number of bytes that will be sent, not including 12-byte RTP headers*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbBytes;
} GF_NTYLBox;

/*32-bits version of tpyl used in Darwin*/
typedef struct
{
	GF_ISOM_BOX
	u32 nbBytes;
} GF_TPAYBox;

/*Maximum data rate in bits per second.*/
typedef struct
{
	GF_ISOM_BOX
	u32 granularity;
	u32 maxDataRate;
} GF_MAXRBox;


/*Total number of bytes from the media track to be sent*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbBytes;
} GF_DMEDBox;

/*Number of bytes of immediate data to be sent*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbBytes;
} GF_DIMMBox;


/*Number of bytes of repeated data to be sent*/
typedef struct
{
	GF_ISOM_BOX
	u64 nbBytes;
} GF_DREPBox;

/*Smallest relative transmission time, in milliseconds. signed integer for smoothing*/
typedef struct
{
	GF_ISOM_BOX
	s32 minTime;
} GF_TMINBox;

/*Largest relative transmission time, in milliseconds.*/
typedef struct
{
	GF_ISOM_BOX
	s32 maxTime;
} GF_TMAXBox;

/*Largest packet, in bytes, including 12-byte RTP header*/
typedef struct
{
	GF_ISOM_BOX
	u32 maxSize;
} GF_PMAXBox;

/*Longest packet duration, in milliseconds*/
typedef struct
{
	GF_ISOM_BOX
	u32 maxDur;
} GF_DMAXBox;

/*32-bit payload type number, followed by rtpmap payload string */
typedef struct
{
	GF_ISOM_BOX
	u32 payloadCode;
	char *payloadString;
} GF_PAYTBox;


typedef struct
{
	GF_ISOM_BOX
	char *string;
} GF_NameBox;

typedef struct
{
	GF_ISOM_BOX
	GF_List *dataRates;
	GF_List *boxList;
} GF_HintInfoBox;



/*
		Data Map (media storage) stuff
*/

/*regular file IO*/
#define GF_ISOM_DATA_FILE			0x01
/*File Mapaing object, read-only mode on complete files (no download)*/
#define GF_ISOM_DATA_FILE_MAPPING		0x02
/*External file object. Needs implementation*/
#define GF_ISOM_DATA_FILE_EXTERN		0x03

/*Data Map modes*/
enum
{
	/*read mode*/
	GF_ISOM_DATA_MAP_READ = 1,
	/*write mode*/
	GF_ISOM_DATA_MAP_WRITE = 2,
	/*the following modes are just ways of signaling extended functionalities
	edit mode, to make sure the file is here, set to GF_ISOM_DATA_MAP_READ afterwards*/
	GF_ISOM_DATA_MAP_EDIT = 3,
	/*read-only access to the movie file: we create a file mapping object
	mode is set to GF_ISOM_DATA_MAP_READ afterwards*/
	GF_ISOM_DATA_MAP_READ_ONLY = 4,
};

/*this is the DataHandler structure each data handler has its own bitstream*/
#define GF_ISOM_BASE_DATA_HANDLER	\
	u8	type;		\
	u64	curPos;		\
	u8	mode;		\
	GF_BitStream *bs;

typedef struct __tag_data_map
{
	GF_ISOM_BASE_DATA_HANDLER
} GF_DataMap;

typedef struct 
{
	GF_ISOM_BASE_DATA_HANDLER
	FILE *stream;
	Bool last_acces_was_read;
#ifndef GPAC_READ_ONLY
	char *temp_file;
#endif
} GF_FileDataMap;

/*file mapping handler. used if supported, only on read mode for complete files  (not in file download)*/
typedef struct 
{
	GF_ISOM_BASE_DATA_HANDLER
	char *name;
	u32 file_size;
	char *byte_map;
	u32 byte_pos;
} GF_FileMappingDataMap;

GF_Err gf_isom_datamap_new(const char *location, const char *parentPath, u8 mode, GF_DataMap **outDataMap);
void gf_isom_datamap_del(GF_DataMap *ptr);
GF_Err gf_isom_datamap_open(GF_MediaBox *minf, u32 dataRefIndex, u8 Edit);
void gf_isom_datamap_close(GF_MediaInformationBox *minf);
u32 gf_isom_datamap_get_data(GF_DataMap *map, char *buffer, u32 bufferLength, u64 Offset);

/*File-based data map*/
GF_DataMap *gf_isom_fdm_new(const char *sPath, u8 mode);
void gf_isom_fdm_del(GF_FileDataMap *ptr);
u32 gf_isom_fdm_get_data(GF_FileDataMap *ptr, char *buffer, u32 bufferLength, u64 fileOffset);

#ifndef GPAC_READ_ONLY
GF_DataMap *gf_isom_fdm_new_temp(const char *sTempPath);
#endif

/*file-mapping, read only*/
GF_DataMap *gf_isom_fmo_new(const char *sPath, u8 mode);
void gf_isom_fmo_del(GF_FileMappingDataMap *ptr);
u32 gf_isom_fmo_get_data(GF_FileMappingDataMap *ptr, char *buffer, u32 bufferLength, u64 fileOffset);

#ifndef GPAC_READ_ONLY
u64 gf_isom_datamap_get_offset(GF_DataMap *map);
GF_Err gf_isom_datamap_add_data(GF_DataMap *ptr, char *data, u32 dataSize);
#endif	

/*
		Movie stuff
*/


/*time def for MP4/QT/MJ2K files*/
#define GF_ISOM_MAC_TIME_OFFSET 2082758400

#ifndef	GF_ISOM_NO_FRAGMENTS
#define GF_ISOM_FORMAT_FRAG_FLAGS(pad, sync, deg) ( ( (pad) << 17) | ( ( !(sync) ) << 16) | (deg) );
#define GF_ISOM_GET_FRAG_PAD(flag) ( (flag) >> 17) & 0x7
#define GF_ISOM_GET_FRAG_SYNC(flag) ( ! ( ( (flag) >> 16) & 0x1))
#define GF_ISOM_GET_FRAG_DEG(flag)	(flag) & 0x7FFF
#endif

enum
{
	GF_ISOM_FRAG_WRITE_READY	=	0x01,
	GF_ISOM_FRAG_READ_DEBUG		=	0x02,
};

/*this is our movie object*/
struct __tag_isom {
	/*the last fatal error*/
	GF_Err LastError;
	/*the original filename*/
	char *fileName;
	/*the original file in read/edit, and also used in fragments mode
	once the first moov has been written
	Nota: this API doesn't allow fragments BEFORE the MOOV in order
	to make easily parsable files (note there could be some data (mdat) before
	the moov*/
	GF_DataMap *movieFileMap;

#ifndef GPAC_READ_ONLY
	/*the final file name*/
	char *finalName;
	/*the file where we store edited samples (for READ_WRITE and WRITE mode only)*/
	GF_DataMap *editFileMap;
	/*the interleaving time for dummy mode (in movie TimeScale)*/
	u32 interleavingTime;
#endif

	u8 openMode;
	u8 storageMode;

	/*main boxes for fast access*/
	/*moov*/
	GF_MovieBox *moov;
	/*our MDAT box (one and only one when we store the file)*/
	GF_MediaDataBox *mdat;
	/*file brand (since v2, NULL means mp4 v1)*/
	GF_FileTypeBox *brand;
	/*progressive download info*/
	GF_ProgressiveDownloadBox *pdin;
	/*meta box if any*/
	GF_MetaBox *meta;

#ifndef	GF_ISOM_NO_FRAGMENTS
	u32 FragmentsFlags, NextMoofNumber;
	/*active fragment*/
	GF_MovieFragmentBox *moof;
	/*in WRITE mode, this is the current MDAT where data is written*/
	/*in READ mode this is the last valid file position before a gf_isom_box_read failed*/
	u64 current_top_box_start;
#endif

	/*this contains ALL the root boxes excepts fragments*/
	GF_List *TopBoxes;

	/*default track for sync of MPEG4 streams - this is the first accessed stream without OCR info - only set in READ mode*/
	s32 es_id_default_sync;
	/*if true 3GPP text streams are read as MPEG-4 StreamingText*/
	Bool convert_streaming_text;
};

/*time function*/
u64 gf_isom_get_mp4time();
/*set the last error of the file. if file is NULL, set the static error (used for IO errors*/
void gf_isom_set_last_error(GF_ISOFile *the_file, GF_Err error);
GF_Err gf_isom_parse_movie_boxes(GF_ISOFile *mov, u64 *bytesMissing);
GF_ISOFile *gf_isom_new_movie();
/*Movie and Track access functions*/
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
GF_TrackBox *gf_isom_get_track(GF_MovieBox *moov, u32 trackNumber);
GF_TrackBox *gf_isom_get_track_from_id(GF_MovieBox *moov, u32 trackID);
u32 gf_isom_get_tracknum_from_id(GF_MovieBox *moov, u32 trackID);
/*open a movie*/
GF_ISOFile *gf_isom_open_file(const char *fileName, u8 OpenMode);
/*close and delete a movie*/
void gf_isom_delete_movie(GF_ISOFile *mov);
/*StreamDescription reconstruction Functions*/
GF_Err GetESD(GF_MovieBox *moov, u32 trackID, u32 StreamDescIndex, GF_ESD **outESD);
GF_Err GetESDForTime(GF_MovieBox *moov, u32 trackID, u64 CTS, GF_ESD **outESD);
GF_Err Media_GetSampleDesc(GF_MediaBox *mdia, u32 SampleDescIndex, GF_SampleEntryBox **out_entry, u32 *dataRefIndex);
GF_Err Media_GetSampleDescIndex(GF_MediaBox *mdia, u64 DTS, u32 *sampleDescIndex);
/*get esd for given sample desc - 
	@true_desc_only: if true doesn't emulate desc and returns native ESD,
				otherwise emulates if needed/possible (TimedText) and return a hard copy of the desc
*/
GF_Err Media_GetESD(GF_MediaBox *mdia, u32 sampleDescIndex, GF_ESD **esd, Bool true_desc_only);
Bool Track_IsMPEG4Stream(u32 HandlerType);
Bool IsMP4Description(u32 entryType);
/*Find a reference of a given type*/
GF_Err Track_FindRef(GF_TrackBox *trak, u32 ReferenceType, GF_TrackReferenceTypeBox **dpnd);
/*Time and sample*/
GF_Err GetMediaTime(GF_TrackBox *trak, u32 movieTime, u64 *MediaTime, s64 *SegmentStartTime, s64 *MediaOffset, u8 *useEdit);
GF_Err Media_GetSample(GF_MediaBox *mdia, u32 sampleNumber, GF_ISOSample **samp, u32 *sampleDescriptionIndex, Bool no_data, u64 *out_offset);
GF_Err Media_CheckDataEntry(GF_MediaBox *mdia, u32 dataEntryIndex);
GF_Err Media_FindSyncSample(GF_SampleTableBox *stbl, u32 searchFromTime, u32 *sampleNumber, u8 mode);
GF_Err Media_RewriteODFrame(GF_MediaBox *mdia, GF_ISOSample *sample);
GF_Err Media_FindDataRef(GF_DataReferenceBox *dref, char *URLname, char *URNname, u32 *dataRefIndex);
Bool Media_IsSelfContained(GF_MediaBox *mdia, u32 StreamDescIndex);

/*check the TimeToSample for the given time and return the Sample number
if the entry is not found, return the closest sampleNumber in prevSampleNumber and 0 in sampleNumber
if the DTS required is after all DTSs in the list, set prevSampleNumber and SampleNumber to 0
useCTS specifies that we're looking for a composition time
*/
GF_Err findEntryForTime(GF_SampleTableBox *stbl, u32 DTS, u8 useCTS, u32 *sampleNumber, u32 *prevSampleNumber);
/*Reading of the sample tables*/
GF_Err stbl_GetSampleSize(GF_SampleSizeBox *stsz, u32 SampleNumber, u32 *Size);
GF_Err stbl_GetSampleCTS(GF_CompositionOffsetBox *ctts, u32 SampleNumber, u32 *CTSoffset);
GF_Err stbl_GetSampleDTS(GF_TimeToSampleBox *stts, u32 SampleNumber, u32 *DTS);
/*find a RAP or set the prev / next RAPs if vars are passed*/
GF_Err stbl_GetSampleRAP(GF_SyncSampleBox *stss, u32 SampleNumber, u8 *IsRAP, u32 *prevRAP, u32 *nextRAP);
GF_Err stbl_GetSampleInfos(GF_SampleTableBox *stbl, u32 sampleNumber, u64 *offset, u32 *chunkNumber, u32 *descIndex, u8 *isEdited);
GF_Err stbl_GetSampleShadow(GF_ShadowSyncBox *stsh, u32 *sampleNumber, u32 *syncNum);
GF_Err stbl_GetPaddingBits(GF_PaddingBitsBox *padb, u32 SampleNumber, u8 *PadBits);
u32 stbl_GetSampleFragmentCount(GF_SampleFragmentBox *stsf, u32 sampleNumber);
u32 stbl_GetSampleFragmentSize(GF_SampleFragmentBox *stsf, u32 sampleNumber, u32 FragmentIndex);
/*unpack sample2chunk and chunk offset so that we have 1 sample per chunk (edition mode only)*/
GF_Err stbl_UnpackOffsets(GF_SampleTableBox *stbl);
GF_Err SetTrackDuration(GF_TrackBox *trak);
GF_Err Media_SetDuration(GF_TrackBox *trak);

/*rewrites 3GP samples desc as MPEG-4 ESD*/
GF_Err gf_isom_get_ttxt_esd(GF_MediaBox *mdia, GF_ESD **out_esd);
/*inserts TTU header - only used when conversion to StreamingText is on*/
GF_Err gf_isom_rewrite_text_sample(GF_ISOSample *samp, u32 sampleDescriptionIndex, u32 sample_dur);

#ifndef GPAC_READ_ONLY

GF_Err FlushCaptureMode(GF_ISOFile *movie);
GF_Err CanAccessMovie(GF_ISOFile *movie, u32 Mode);
GF_ISOFile *MovieCreate(const char *fileName, u8 OpenMode);
void gf_isom_insert_moov(GF_ISOFile *file);

GF_Err WriteToFile(GF_ISOFile *movie, void (*progress)(void *cbk, u32 done, u32 total), void *cbck);
GF_Err Track_SetStreamDescriptor(GF_TrackBox *trak, u32 StreamDescriptionIndex, u32 DataReferenceIndex, GF_ESD *esd, u32 *outStreamIndex);
u8 RequestTrack(GF_MovieBox *moov, u32 TrackID);
/*Track-Media setup*/
GF_Err NewMedia(GF_MediaBox **mdia, u32 MediaType, u32 TimeScale);
GF_Err Media_ParseODFrame(GF_MediaBox *mdia, GF_ISOSample *sample);
GF_Err Media_AddSample(GF_MediaBox *mdia, u64 data_offset, GF_ISOSample *sample, u32 StreamDescIndex, u32 syncShadowNumber);
GF_Err Media_CreateDataRef(GF_DataReferenceBox *dref, char *URLname, char *URNname, u32 *dataRefIndex);
/*update a media sample. ONLY in edit mode*/
GF_Err Media_UpdateSample(GF_MediaBox *mdia, u32 sampleNumber, GF_ISOSample *sample, Bool data_only);
GF_Err Media_UpdateSampleReference(GF_MediaBox *mdia, u32 sampleNumber, GF_ISOSample *sample, u64 data_offset);
/*addition in the sample tables*/
GF_Err stbl_AddDTS(GF_SampleTableBox *stbl, u32 DTS, u32 *sampleNumber, u32 LastAUDefDuration);
GF_Err stbl_AddCTS(GF_SampleTableBox *stbl, u32 sampleNumber, u32 CTSoffset);
GF_Err stbl_AddSize(GF_SampleSizeBox *stsz, u32 sampleNumber, u32 size);
GF_Err stbl_AddRAP(GF_SyncSampleBox *stss, u32 sampleNumber);
GF_Err stbl_AddShadow(GF_ShadowSyncBox *stsh, u32 sampleNumber, u32 shadowNumber);
GF_Err stbl_AddChunkOffset(GF_MediaBox *mdia, u32 sampleNumber, u32 StreamDescIndex, u64 offset);
/*NB - no add for padding, this is done only through SetPaddingBits*/

GF_Err stbl_AddSampleFragment(GF_SampleTableBox *stbl, u32 sampleNumber, u16 size);

/*update of the sample table
all these functions are called in edit and we always have 1 sample per chunk*/
GF_Err stbl_SetChunkOffset(GF_MediaBox *mdia, u32 sampleNumber, u64 offset);
GF_Err stbl_SetSampleCTS(GF_SampleTableBox *stbl, u32 sampleNumber, u32 offset);
GF_Err stbl_SetSampleSize(GF_SampleSizeBox *stsz, u32 SampleNumber, u32 size);
GF_Err stbl_SetSampleRAP(GF_SyncSampleBox *stss, u32 SampleNumber, u8 isRAP);
GF_Err stbl_SetSyncShadow(GF_ShadowSyncBox *stsh, u32 sampleNumber, u32 syncSample);
GF_Err stbl_SetPaddingBits(GF_SampleTableBox *stbl, u32 SampleNumber, u8 bits);
/*for adding fragmented samples*/
GF_Err stbl_SampleSizeAppend(GF_SampleSizeBox *stsz, u32 data_size);
/*writing of the final chunk info in edit mode*/
GF_Err stbl_SetChunkAndOffset(GF_SampleTableBox *stbl, u32 sampleNumber, u32 StreamDescIndex, GF_SampleToChunkBox *the_stsc, GF_Box **the_stco, u64 data_offset, u8 forceNewChunk);
/*EDIT LIST functions*/
GF_EdtsEntry *CreateEditEntry(u32 EditDuration, u32 MediaTime, u8 EditMode);

/*REMOVE functions*/
GF_Err stbl_RemoveDTS(GF_SampleTableBox *stbl, u32 sampleNumber, u32 LastAUDefDuration);
GF_Err stbl_RemoveCTS(GF_SampleTableBox *stbl, u32 sampleNumber);
GF_Err stbl_RemoveSize(GF_SampleSizeBox *stsz, u32 sampleNumber);
GF_Err stbl_RemoveChunk(GF_SampleTableBox *stbl, u32 sampleNumber);
GF_Err stbl_RemoveRAP(GF_SampleTableBox *stbl, u32 sampleNumber);
GF_Err stbl_RemoveShadow(GF_ShadowSyncBox *stsh, u32 sampleNumber);
GF_Err stbl_RemovePaddingBits(GF_SampleTableBox *stbl, u32 SampleNumber);
GF_Err stbl_RemoveSampleFragments(GF_SampleTableBox *stbl, u32 sampleNumber);

#ifndef	GF_ISOM_NO_FRAGMENTS
GF_Err StoreFragment(GF_ISOFile *movie);
#endif

#endif	

Bool IsHintTrack(GF_TrackBox *trak);
Bool CheckHintFormat(GF_TrackBox *trak, u32 HintType);
u32 GetHintFormat(GF_TrackBox *trak);



/*
		Hinting stuff
*/

/*the HintType for each protocol*/
enum
{
	GF_ISMO_HINT_RTP	= 1,
	/*not supported yet*/
	GF_ISMO_MPEG2_TS	= 2
};

/*****************************************************
		RTP Data Entries
*****************************************************/

#define GF_ISMO_BASE_DTE_ENTRY	\
	u8 source;

typedef struct
{
	GF_ISMO_BASE_DTE_ENTRY
} GF_GenericDTE;

typedef struct
{
	GF_ISMO_BASE_DTE_ENTRY
} GF_EmptyDTE;

typedef struct
{
	GF_ISMO_BASE_DTE_ENTRY
	u8 dataLength;
	char data[14];
} GF_ImmediateDTE;

typedef struct
{
	GF_ISMO_BASE_DTE_ENTRY
	s8 trackRefIndex;
	u32 sampleNumber;
	u16 dataLength;
	u32 byteOffset;
	u16 bytesPerComp;
	u16 samplesPerComp;
} GF_SampleDTE;

typedef struct
{
	GF_ISMO_BASE_DTE_ENTRY
	s8 trackRefIndex;
	u32 streamDescIndex;
	u16 dataLength;
	u32 byteOffset;
	u32 reserved;
} GF_StreamDescDTE;

GF_GenericDTE *NewDTE(u8 type);
void DelDTE(GF_GenericDTE *dte);
GF_Err ReadDTE(GF_GenericDTE *dte, GF_BitStream *bs);
GF_Err WriteDTE(GF_GenericDTE *dte, GF_BitStream *bs);
GF_Err OffsetDTE(GF_GenericDTE *dte, u32 offset, u32 HintSampleNumber);

/*****************************************************
		RTP Sample
*****************************************************/

/*data cache when reading*/
typedef struct __tag_hint_data_cache
{
	GF_ISOSample *samp;
	GF_TrackBox *trak;
	u32 sample_num;
} GF_HintDataCache;


typedef struct __tag_hint_sample
{
	/*used internally for future protocol support (write only)*/
	u8 HintType;
	/*QT packets*/
	u16 reserved;
	GF_List *packetTable;
	char *AdditionalData;
	u32 dataLength;
	/*used internally for hinting*/
	u32 TransmissionTime;
	/*for read only, used to store samples fetched while building packets*/
	GF_List *sample_cache;
} GF_HintSample;

GF_HintSample *gf_isom_hint_sample_new();
void gf_isom_hint_sample_del(GF_HintSample *ptr);
GF_Err gf_isom_hint_sample_read(GF_HintSample *ptr, GF_BitStream *bs, u32 sampleSize);
u32 gf_isom_hint_sample_write(GF_HintSample *ptr, GF_BitStream *bs);
u32 gf_isom_hint_sample_size(GF_HintSample *ptr);

/*****************************************************
		Hint Packets (generic packet for future protocol support)
*****************************************************/
#define GF_ISOM_BASE_PACKET			\
	s32 relativeTransTime;


typedef struct
{
	GF_ISOM_BASE_PACKET
} GF_HintPacket;

GF_HintPacket *gf_isom_hint_pck_new(u8 HintType);
void gf_isom_hint_pck_del(u8 HintType, GF_HintPacket *ptr);
GF_Err gf_isom_hint_pck_read(u8 HintType, GF_HintPacket *ptr, GF_BitStream *bs);
GF_Err gf_isom_hint_pck_write(u8 HintType, GF_HintPacket *ptr, GF_BitStream *bs);
u32 gf_isom_hint_pck_size(u8 HintType, GF_HintPacket *ptr);
GF_Err gf_isom_hint_pck_offset(u8 HintType, GF_HintPacket *ptr, u32 offset, u32 HintSampleNumber);
GF_Err gf_isom_hint_pck_add_dte(u8 HintType, GF_HintPacket *ptr, GF_GenericDTE *dte, u8 AtBegin);
/*get the size of the packet AS RECONSTRUCTED BY THE SERVER (without CSRC)*/
u32 gf_isom_hint_pck_length(u8 HintType, GF_HintPacket *ptr);

/*the RTP packet*/
typedef struct
{
	GF_ISOM_BASE_PACKET	
	
	/*RTP Header*/
	u8 P_bit;
	u8 X_bit;
	u8 M_bit;
	/*on 7 bits */
	u8 payloadType;
	u16 SequenceNumber;
	/*Hinting flags*/
	u8 B_bit;
	u8 R_bit;
	/*ExtraInfos TLVs - not really used */
	GF_List *TLV;
	/*DataTable - contains the DTEs...*/
	GF_List *DataTable;
} GF_RTPPacket;

GF_RTPPacket *gf_isom_hint_rtp_new();
void gf_isom_hint_rtp_del(GF_RTPPacket *ptr);
GF_Err gf_isom_hint_rtp_read(GF_RTPPacket *ptr, GF_BitStream *bs);
GF_Err gf_isom_hint_rtp_write(GF_RTPPacket *ptr, GF_BitStream *bs);
u32 gf_isom_hint_rtp_size(GF_RTPPacket *ptr);
GF_Err gf_isom_hint_rtp_offset(GF_RTPPacket *ptr, u32 offset, u32 HintSampleNumber);
u32 gf_isom_hint_rtp_length(GF_RTPPacket *ptr);



struct _3gpp_text_sample 
{
	char *text;
	u32 len;
	
	GF_TextStyleBox *styles;
	/*at most one of these*/
	GF_TextHighlightColorBox *highlight_color;
	GF_TextScrollDelayBox *scroll_delay;
	GF_TextBoxBox *box;
	GF_TextWrapBox *wrap;

	GF_List *others;
	GF_TextKaraokeBox *cur_karaoke;
};

GF_TextSample *gf_isom_parse_texte_sample(GF_BitStream *bs);
GF_TextSample *gf_isom_parse_texte_sample_from_data(char *data, u32 dataLength);



/*
	these are exported just in case, there should never be needed outside the lib
*/

GF_Box *reftype_New();
GF_Box *free_New();
GF_Box *mdat_New();
GF_Box *moov_New();
GF_Box *mvhd_New();
GF_Box *mdhd_New();
GF_Box *vmhd_New();
GF_Box *smhd_New();
GF_Box *hmhd_New();
GF_Box *nmhd_New();
GF_Box *stbl_New();
GF_Box *dinf_New();
GF_Box *url_New();
GF_Box *urn_New();
GF_Box *cprt_New();
GF_Box *chpl_New();
GF_Box *hdlr_New();
GF_Box *iods_New();
GF_Box *trak_New();
GF_Box *mp4s_New();
GF_Box *mp4v_New();
GF_Box *mp4a_New();
GF_Box *edts_New();
GF_Box *udta_New();
GF_Box *dref_New();
GF_Box *stsd_New();
GF_Box *stts_New();
GF_Box *ctts_New();
GF_Box *stsh_New();
GF_Box *elst_New();
GF_Box *stsc_New();
GF_Box *stsz_New();
GF_Box *stco_New();
GF_Box *stss_New();
GF_Box *stdp_New();
GF_Box *co64_New();
GF_Box *esds_New();
GF_Box *minf_New();
GF_Box *tkhd_New();
GF_Box *tref_New();
GF_Box *mdia_New();
GF_Box *defa_New();
GF_Box *void_New();
GF_Box *stsf_New();
GF_Box *gnrm_New();
GF_Box *gnrv_New();
GF_Box *gnra_New();
GF_Box *pdin_New();

void reftype_del(GF_Box *);
void free_del(GF_Box *);
void mdat_del(GF_Box *);
void moov_del(GF_Box *);
void mvhd_del(GF_Box *);
void mdhd_del(GF_Box *);
void vmhd_del(GF_Box *);
void smhd_del(GF_Box *);
void hmhd_del(GF_Box *);
void nmhd_del(GF_Box *);
void stbl_del(GF_Box *);
void dinf_del(GF_Box *);
void url_del(GF_Box *);
void urn_del(GF_Box *);
void chpl_del(GF_Box *);
void cprt_del(GF_Box *);
void hdlr_del(GF_Box *);
void iods_del(GF_Box *);
void trak_del(GF_Box *);
void mp4s_del(GF_Box *);
void mp4v_del(GF_Box *);
void mp4a_del(GF_Box *);
void edts_del(GF_Box *);
void udta_del(GF_Box *);
void dref_del(GF_Box *);
void stsd_del(GF_Box *);
void stts_del(GF_Box *);
void ctts_del(GF_Box *);
void stsh_del(GF_Box *);
void elst_del(GF_Box *);
void stsc_del(GF_Box *);
void stsz_del(GF_Box *);
void stco_del(GF_Box *);
void stss_del(GF_Box *);
void stdp_del(GF_Box *);
void co64_del(GF_Box *);
void esds_del(GF_Box *);
void minf_del(GF_Box *);
void tkhd_del(GF_Box *);
void tref_del(GF_Box *);
void mdia_del(GF_Box *);
void defa_del(GF_Box *);
void void_del(GF_Box *);
void stsf_del(GF_Box *);
void gnrm_del(GF_Box *);
void gnrv_del(GF_Box *);
void gnra_del(GF_Box *);
void pdin_del(GF_Box *);

GF_Err reftype_Write(GF_Box *s, GF_BitStream *bs);
GF_Err free_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mdat_Write(GF_Box *s, GF_BitStream *bs);
GF_Err moov_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mvhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mdhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err vmhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err smhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err hmhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err nmhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stbl_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dinf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err url_Write(GF_Box *s, GF_BitStream *bs);
GF_Err urn_Write(GF_Box *s, GF_BitStream *bs);
GF_Err chpl_Write(GF_Box *s, GF_BitStream *bs);
GF_Err cprt_Write(GF_Box *s, GF_BitStream *bs);
GF_Err hdlr_Write(GF_Box *s, GF_BitStream *bs);
GF_Err iods_Write(GF_Box *s, GF_BitStream *bs);
GF_Err trak_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mp4s_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mp4v_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mp4a_Write(GF_Box *s, GF_BitStream *bs);
GF_Err edts_Write(GF_Box *s, GF_BitStream *bs);
GF_Err udta_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dref_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stsd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stts_Write(GF_Box *s, GF_BitStream *bs);
GF_Err ctts_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stsh_Write(GF_Box *s, GF_BitStream *bs);
GF_Err elst_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stsc_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stsz_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stco_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stss_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stdp_Write(GF_Box *s, GF_BitStream *bs);
GF_Err co64_Write(GF_Box *s, GF_BitStream *bs);
GF_Err esds_Write(GF_Box *s, GF_BitStream *bs);
GF_Err minf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tkhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tref_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mdia_Write(GF_Box *s, GF_BitStream *bs);
GF_Err defa_Write(GF_Box *s, GF_BitStream *bs);
GF_Err void_Write(GF_Box *s, GF_BitStream *bs);
GF_Err stsf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gnrm_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gnrv_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gnra_Write(GF_Box *s, GF_BitStream *bs);
GF_Err pdin_Write(GF_Box *s, GF_BitStream *bs);

GF_Err reftype_Size(GF_Box *);
GF_Err free_Size(GF_Box *);
GF_Err mdat_Size(GF_Box *);
GF_Err moov_Size(GF_Box *);
GF_Err mvhd_Size(GF_Box *);
GF_Err mdhd_Size(GF_Box *);
GF_Err vmhd_Size(GF_Box *);
GF_Err smhd_Size(GF_Box *);
GF_Err hmhd_Size(GF_Box *);
GF_Err nmhd_Size(GF_Box *);
GF_Err stbl_Size(GF_Box *);
GF_Err dinf_Size(GF_Box *);
GF_Err url_Size(GF_Box *);
GF_Err urn_Size(GF_Box *);
GF_Err chpl_Size(GF_Box *);
GF_Err cprt_Size(GF_Box *);
GF_Err hdlr_Size(GF_Box *);
GF_Err iods_Size(GF_Box *);
GF_Err trak_Size(GF_Box *);
GF_Err mp4s_Size(GF_Box *);
GF_Err mp4v_Size(GF_Box *);
GF_Err mp4a_Size(GF_Box *);
GF_Err edts_Size(GF_Box *);
GF_Err udta_Size(GF_Box *);
GF_Err dref_Size(GF_Box *);
GF_Err stsd_Size(GF_Box *);
GF_Err stts_Size(GF_Box *);
GF_Err ctts_Size(GF_Box *);
GF_Err stsh_Size(GF_Box *);
GF_Err elst_Size(GF_Box *);
GF_Err stsc_Size(GF_Box *);
GF_Err stsz_Size(GF_Box *);
GF_Err stco_Size(GF_Box *);
GF_Err stss_Size(GF_Box *);
GF_Err stdp_Size(GF_Box *);
GF_Err co64_Size(GF_Box *);
GF_Err esds_Size(GF_Box *);
GF_Err minf_Size(GF_Box *);
GF_Err tkhd_Size(GF_Box *);
GF_Err tref_Size(GF_Box *);
GF_Err mdia_Size(GF_Box *);
GF_Err defa_Size(GF_Box *);
GF_Err void_Size(GF_Box *);
GF_Err stsf_Size(GF_Box *);
GF_Err gnrm_Size(GF_Box *);
GF_Err gnrv_Size(GF_Box *);
GF_Err gnra_Size(GF_Box *);
GF_Err pdin_Size(GF_Box *);

GF_Err reftype_Read(GF_Box *s, GF_BitStream *bs);
GF_Err free_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mdat_Read(GF_Box *s, GF_BitStream *bs);
GF_Err moov_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mvhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mdhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err vmhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err smhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err hmhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err nmhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stbl_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dinf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err url_Read(GF_Box *s, GF_BitStream *bs);
GF_Err urn_Read(GF_Box *s, GF_BitStream *bs);
GF_Err chpl_Read(GF_Box *s, GF_BitStream *bs);
GF_Err cprt_Read(GF_Box *s, GF_BitStream *bs);
GF_Err hdlr_Read(GF_Box *s, GF_BitStream *bs);
GF_Err iods_Read(GF_Box *s, GF_BitStream *bs);
GF_Err trak_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mp4s_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mp4v_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mp4a_Read(GF_Box *s, GF_BitStream *bs);
GF_Err edts_Read(GF_Box *s, GF_BitStream *bs);
GF_Err udta_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dref_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stsd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stts_Read(GF_Box *s, GF_BitStream *bs);
GF_Err ctts_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stsh_Read(GF_Box *s, GF_BitStream *bs);
GF_Err elst_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stsc_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stsz_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stco_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stss_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stdp_Read(GF_Box *s, GF_BitStream *bs);
GF_Err co64_Read(GF_Box *s, GF_BitStream *bs);
GF_Err esds_Read(GF_Box *s, GF_BitStream *bs);
GF_Err minf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tkhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tref_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mdia_Read(GF_Box *s, GF_BitStream *bs);
GF_Err defa_Read(GF_Box *s, GF_BitStream *bs);
GF_Err void_Read(GF_Box *s, GF_BitStream *bs);
GF_Err stsf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err pdin_Read(GF_Box *s, GF_BitStream *bs);


GF_Box *hinf_New();
GF_Box *trpy_New();
GF_Box *totl_New();
GF_Box *nump_New();
GF_Box *npck_New();
GF_Box *tpyl_New();
GF_Box *tpay_New();
GF_Box *maxr_New();
GF_Box *dmed_New();
GF_Box *dimm_New();
GF_Box *drep_New();
GF_Box *tmin_New();
GF_Box *tmax_New();
GF_Box *pmax_New();
GF_Box *dmax_New();
GF_Box *payt_New();
GF_Box *name_New();
GF_Box *rely_New();
GF_Box *snro_New();
GF_Box *tims_New();
GF_Box *tsro_New();
GF_Box *ghnt_New();
GF_Box *hnti_New();
GF_Box *sdp_New();
GF_Box *rtpo_New();

void hinf_del(GF_Box *s);
void trpy_del(GF_Box *s);
void totl_del(GF_Box *s);
void nump_del(GF_Box *s);
void npck_del(GF_Box *s);
void tpyl_del(GF_Box *s);
void tpay_del(GF_Box *s);
void maxr_del(GF_Box *s);
void dmed_del(GF_Box *s);
void dimm_del(GF_Box *s);
void drep_del(GF_Box *s);
void tmin_del(GF_Box *s);
void tmax_del(GF_Box *s);
void pmax_del(GF_Box *s);
void dmax_del(GF_Box *s);
void payt_del(GF_Box *s);
void name_del(GF_Box *s);
void rely_del(GF_Box *s);
void snro_del(GF_Box *s);
void tims_del(GF_Box *s);
void tsro_del(GF_Box *s);
void ghnt_del(GF_Box *s);
void hnti_del(GF_Box *a);
void sdp_del(GF_Box *a);
void rtpo_del(GF_Box *s);

GF_Err hinf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err trpy_Read(GF_Box *s, GF_BitStream *bs);
GF_Err totl_Read(GF_Box *s, GF_BitStream *bs);
GF_Err nump_Read(GF_Box *s, GF_BitStream *bs);
GF_Err npck_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tpyl_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tpay_Read(GF_Box *s, GF_BitStream *bs);
GF_Err maxr_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dmed_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dimm_Read(GF_Box *s, GF_BitStream *bs);
GF_Err drep_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tmin_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tmax_Read(GF_Box *s, GF_BitStream *bs);
GF_Err pmax_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dmax_Read(GF_Box *s, GF_BitStream *bs);
GF_Err payt_Read(GF_Box *s, GF_BitStream *bs);
GF_Err name_Read(GF_Box *s, GF_BitStream *bs);
GF_Err rely_Read(GF_Box *s, GF_BitStream *bs);
GF_Err snro_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tims_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tsro_Read(GF_Box *s, GF_BitStream *bs);
GF_Err ghnt_Read(GF_Box *s, GF_BitStream *bs);
GF_Err hnti_Read(GF_Box *s, GF_BitStream *bs);
GF_Err sdp_Read(GF_Box *s, GF_BitStream *bs);
GF_Err rtpo_Read(GF_Box *s, GF_BitStream *bs);

GF_Err hinf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err trpy_Write(GF_Box *s, GF_BitStream *bs);
GF_Err totl_Write(GF_Box *s, GF_BitStream *bs);
GF_Err nump_Write(GF_Box *s, GF_BitStream *bs);
GF_Err npck_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tpyl_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tpay_Write(GF_Box *s, GF_BitStream *bs);
GF_Err maxr_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dmed_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dimm_Write(GF_Box *s, GF_BitStream *bs);
GF_Err drep_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tmin_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tmax_Write(GF_Box *s, GF_BitStream *bs);
GF_Err pmax_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dmax_Write(GF_Box *s, GF_BitStream *bs);
GF_Err payt_Write(GF_Box *s, GF_BitStream *bs);
GF_Err name_Write(GF_Box *s, GF_BitStream *bs);
GF_Err rely_Write(GF_Box *s, GF_BitStream *bs);
GF_Err snro_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tims_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tsro_Write(GF_Box *s, GF_BitStream *bs);
GF_Err ghnt_Write(GF_Box *s, GF_BitStream *bs);
GF_Err hnti_Write(GF_Box *s, GF_BitStream *bs);
GF_Err sdp_Write(GF_Box *s, GF_BitStream *bs);
GF_Err rtpo_Write(GF_Box *s, GF_BitStream *bs);

GF_Err hinf_Size(GF_Box *s);
GF_Err trpy_Size(GF_Box *s);
GF_Err totl_Size(GF_Box *s);
GF_Err nump_Size(GF_Box *s);
GF_Err npck_Size(GF_Box *s);
GF_Err tpyl_Size(GF_Box *s);
GF_Err tpay_Size(GF_Box *s);
GF_Err maxr_Size(GF_Box *s);
GF_Err dmed_Size(GF_Box *s);
GF_Err dimm_Size(GF_Box *s);
GF_Err drep_Size(GF_Box *s);
GF_Err tmin_Size(GF_Box *s);
GF_Err tmax_Size(GF_Box *s);
GF_Err pmax_Size(GF_Box *s);
GF_Err dmax_Size(GF_Box *s);
GF_Err payt_Size(GF_Box *s);
GF_Err name_Size(GF_Box *s);
GF_Err rely_Size(GF_Box *s);
GF_Err snro_Size(GF_Box *s);
GF_Err tims_Size(GF_Box *s);
GF_Err tsro_Size(GF_Box *s);
GF_Err ghnt_Size(GF_Box *s);
GF_Err hnti_Size(GF_Box *s);
GF_Err sdp_Size(GF_Box *s);
GF_Err rtpo_Size(GF_Box *s);


GF_Box *ftyp_New();
void ftyp_del(GF_Box *s);
GF_Err ftyp_Read(GF_Box *s,GF_BitStream *bs);
GF_Err ftyp_Write(GF_Box *s, GF_BitStream *bs);
GF_Err ftyp_Size(GF_Box *s);

GF_Box *padb_New();
void padb_del(GF_Box *s);
GF_Err padb_Read(GF_Box *s, GF_BitStream *bs);
GF_Err padb_Write(GF_Box *s, GF_BitStream *bs);
GF_Err padb_Size(GF_Box *s);

GF_Box *gppa_New(u32 type);
GF_Box *gppv_New(u32 type);
GF_Box *gppc_New(u32 type);
void gppa_del(GF_Box *s);
void gppv_del(GF_Box *s);
void gppc_del(GF_Box *s);
GF_Err gppa_Read(GF_Box *s, GF_BitStream *bs);
GF_Err gppv_Read(GF_Box *s, GF_BitStream *bs);
GF_Err gppc_Read(GF_Box *s, GF_BitStream *bs);
#ifndef GPAC_READ_ONLY
GF_Err gppa_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gppv_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gppc_Write(GF_Box *s, GF_BitStream *bs);
GF_Err gppa_Size(GF_Box *s);
GF_Err gppv_Size(GF_Box *s);
GF_Err gppc_Size(GF_Box *s);
#endif


#ifndef	GF_ISOM_NO_FRAGMENTS
GF_Box *mvex_New();
GF_Box *trex_New();
GF_Box *moof_New();
GF_Box *mfhd_New();
GF_Box *traf_New();
GF_Box *tfhd_New();
GF_Box *trun_New();

void mvex_del(GF_Box *s);
void trex_del(GF_Box *s);
void moof_del(GF_Box *s);
void mfhd_del(GF_Box *s);
void traf_del(GF_Box *s);
void tfhd_del(GF_Box *s);
void trun_del(GF_Box *s);

GF_Err mvex_Read(GF_Box *s, GF_BitStream *bs);
GF_Err trex_Read(GF_Box *s, GF_BitStream *bs);
GF_Err moof_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mfhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err traf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tfhd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err trun_Read(GF_Box *s, GF_BitStream *bs);

GF_Err mvex_Write(GF_Box *s, GF_BitStream *bs);
GF_Err trex_Write(GF_Box *s, GF_BitStream *bs);
GF_Err moof_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mfhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err traf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tfhd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err trun_Write(GF_Box *s, GF_BitStream *bs);

GF_Err mvex_Size(GF_Box *s);
GF_Err trex_Size(GF_Box *s);
GF_Err moof_Size(GF_Box *s);
GF_Err mfhd_Size(GF_Box *s);
GF_Err traf_Size(GF_Box *s);
GF_Err tfhd_Size(GF_Box *s);
GF_Err trun_Size(GF_Box *s);


GF_Box *mehd_New();
void mehd_del(GF_Box *s);
GF_Err mehd_Read(GF_Box *s, GF_BitStream *bs);
GF_Err mehd_Write(GF_Box *s, GF_BitStream *bs);
GF_Err mehd_Size(GF_Box *s);

#endif 

/*avc ext*/
GF_Box *avcc_New();
void avcc_del(GF_Box *s);
GF_Err avcc_Read(GF_Box *s, GF_BitStream *bs);
GF_Err avcc_Write(GF_Box *s, GF_BitStream *bs);
GF_Err avcc_Size(GF_Box *s);

GF_Box *avc1_New();
void avc1_del(GF_Box *s);
GF_Err avc1_Read(GF_Box *s, GF_BitStream *bs);
GF_Err avc1_Write(GF_Box *s, GF_BitStream *bs);
GF_Err avc1_Size(GF_Box *s);

GF_Box *m4ds_New();
void m4ds_del(GF_Box *s);
GF_Err m4ds_Read(GF_Box *s, GF_BitStream *bs);
GF_Err m4ds_Write(GF_Box *s, GF_BitStream *bs);
GF_Err m4ds_Size(GF_Box *s);

GF_Box *btrt_New();
void btrt_del(GF_Box *s);
GF_Err btrt_Read(GF_Box *s, GF_BitStream *bs);
GF_Err btrt_Write(GF_Box *s, GF_BitStream *bs);
GF_Err btrt_Size(GF_Box *s);


/*3GPP streaming text*/
GF_Box *ftab_New();
GF_Box *tx3g_New();
GF_Box *styl_New();
GF_Box *hlit_New();
GF_Box *hclr_New();
GF_Box *krok_New();
GF_Box *dlay_New();
GF_Box *href_New();
GF_Box *tbox_New();
GF_Box *blnk_New();
GF_Box *twrp_New();

void ftab_del(GF_Box *s);
void tx3g_del(GF_Box *s);
void styl_del(GF_Box *s);
void hlit_del(GF_Box *s);
void hclr_del(GF_Box *s);
void krok_del(GF_Box *s);
void dlay_del(GF_Box *s);
void href_del(GF_Box *s);
void tbox_del(GF_Box *s);
void blnk_del(GF_Box *s);
void twrp_del(GF_Box *s);

GF_Err ftab_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tx3g_Read(GF_Box *s, GF_BitStream *bs);
GF_Err styl_Read(GF_Box *s, GF_BitStream *bs);
GF_Err hlit_Read(GF_Box *s, GF_BitStream *bs);
GF_Err hclr_Read(GF_Box *s, GF_BitStream *bs);
GF_Err krok_Read(GF_Box *s, GF_BitStream *bs);
GF_Err dlay_Read(GF_Box *s, GF_BitStream *bs);
GF_Err href_Read(GF_Box *s, GF_BitStream *bs);
GF_Err tbox_Read(GF_Box *s, GF_BitStream *bs);
GF_Err blnk_Read(GF_Box *s, GF_BitStream *bs);
GF_Err twrp_Read(GF_Box *s, GF_BitStream *bs);

#ifndef GPAC_READ_ONLY
GF_Err ftab_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tx3g_Write(GF_Box *s, GF_BitStream *bs);
GF_Err styl_Write(GF_Box *s, GF_BitStream *bs);
GF_Err hlit_Write(GF_Box *s, GF_BitStream *bs);
GF_Err hclr_Write(GF_Box *s, GF_BitStream *bs);
GF_Err krok_Write(GF_Box *s, GF_BitStream *bs);
GF_Err dlay_Write(GF_Box *s, GF_BitStream *bs);
GF_Err href_Write(GF_Box *s, GF_BitStream *bs);
GF_Err tbox_Write(GF_Box *s, GF_BitStream *bs);
GF_Err blnk_Write(GF_Box *s, GF_BitStream *bs);
GF_Err twrp_Write(GF_Box *s, GF_BitStream *bs);

GF_Err ftab_Size(GF_Box *s);
GF_Err tx3g_Size(GF_Box *s);
GF_Err styl_Size(GF_Box *s);
GF_Err hlit_Size(GF_Box *s);
GF_Err hclr_Size(GF_Box *s);
GF_Err krok_Size(GF_Box *s);
GF_Err dlay_Size(GF_Box *s);
GF_Err href_Size(GF_Box *s);
GF_Err tbox_Size(GF_Box *s);
GF_Err blnk_Size(GF_Box *s);
GF_Err twrp_Size(GF_Box *s);
#endif


/* MPEG-21 functions */
GF_Box *meta_New();
GF_Box *xml_New();
GF_Box *bxml_New();
GF_Box *iloc_New();
GF_Box *pitm_New();
GF_Box *ipro_New();
GF_Box *infe_New();
GF_Box *iinf_New();
GF_Box *imif_New();
GF_Box *ipmc_New();
GF_Box *sinf_New();
GF_Box *frma_New();
GF_Box *schm_New();
GF_Box *schi_New();
GF_Box *enca_New();
GF_Box *encv_New();
GF_Box *encs_New();

void meta_del(GF_Box *s);
void xml_del(GF_Box *s);
void bxml_del(GF_Box *s);
void iloc_del(GF_Box *s);
void pitm_del(GF_Box *s);
void ipro_del(GF_Box *s);
void infe_del(GF_Box *s);
void iinf_del(GF_Box *s);
void imif_del(GF_Box *s);
void ipmc_del(GF_Box *s);
void sinf_del(GF_Box *s);
void frma_del(GF_Box *s);
void schm_del(GF_Box *s);
void schi_del(GF_Box *s);

GF_Err meta_Read(GF_Box *s, GF_BitStream *bs);
GF_Err xml_Read(GF_Box *s, GF_BitStream *bs);
GF_Err bxml_Read(GF_Box *s, GF_BitStream *bs);
GF_Err iloc_Read(GF_Box *s, GF_BitStream *bs);
GF_Err pitm_Read(GF_Box *s, GF_BitStream *bs);
GF_Err ipro_Read(GF_Box *s, GF_BitStream *bs);
GF_Err infe_Read(GF_Box *s, GF_BitStream *bs);
GF_Err iinf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err imif_Read(GF_Box *s, GF_BitStream *bs);
GF_Err ipmc_Read(GF_Box *s, GF_BitStream *bs);
GF_Err sinf_Read(GF_Box *s, GF_BitStream *bs);
GF_Err frma_Read(GF_Box *s, GF_BitStream *bs);
GF_Err schm_Read(GF_Box *s, GF_BitStream *bs);
GF_Err schi_Read(GF_Box *s, GF_BitStream *bs);

#ifndef GPAC_READ_ONLY
GF_Err meta_Write(GF_Box *s, GF_BitStream *bs);
GF_Err xml_Write(GF_Box *s, GF_BitStream *bs);
GF_Err bxml_Write(GF_Box *s, GF_BitStream *bs);
GF_Err iloc_Write(GF_Box *s, GF_BitStream *bs);
GF_Err pitm_Write(GF_Box *s, GF_BitStream *bs);
GF_Err ipro_Write(GF_Box *s, GF_BitStream *bs);
GF_Err infe_Write(GF_Box *s, GF_BitStream *bs);
GF_Err iinf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err imif_Write(GF_Box *s, GF_BitStream *bs);
GF_Err ipmc_Write(GF_Box *s, GF_BitStream *bs);
GF_Err sinf_Write(GF_Box *s, GF_BitStream *bs);
GF_Err frma_Write(GF_Box *s, GF_BitStream *bs);
GF_Err schm_Write(GF_Box *s, GF_BitStream *bs);
GF_Err schi_Write(GF_Box *s, GF_BitStream *bs);

GF_Err meta_Size(GF_Box *s);
GF_Err xml_Size(GF_Box *s);
GF_Err bxml_Size(GF_Box *s);
GF_Err iloc_Size(GF_Box *s);
GF_Err pitm_Size(GF_Box *s);
GF_Err ipro_Size(GF_Box *s);
GF_Err infe_Size(GF_Box *s);
GF_Err iinf_Size(GF_Box *s);
GF_Err imif_Size(GF_Box *s);
GF_Err ipmc_Size(GF_Box *s);
GF_Err sinf_Size(GF_Box *s);
GF_Err frma_Size(GF_Box *s);
GF_Err schm_Size(GF_Box *s);
GF_Err schi_Size(GF_Box *s);
#endif

/* end of MPEG-21 functions */


/** ISMACryp functions **/
GF_Box *iKMS_New();
GF_Box *iSFM_New();
void iKMS_del(GF_Box *s);
void iSFM_del(GF_Box *s);
GF_Err iKMS_Read(GF_Box *s, GF_BitStream *bs);
GF_Err iSFM_Read(GF_Box *s, GF_BitStream *bs);
#ifndef GPAC_READ_ONLY
GF_Err iKMS_Write(GF_Box *s, GF_BitStream *bs);
GF_Err iSFM_Write(GF_Box *s, GF_BitStream *bs);
GF_Err iKMS_Size(GF_Box *s);
GF_Err iSFM_Size(GF_Box *s);
#endif

GF_Err gb_box_array_dump(GF_List *list, FILE * trace);
GF_Err reftype_dump(GF_Box *a, FILE * trace);
GF_Err free_dump(GF_Box *a, FILE * trace);
GF_Err mdat_dump(GF_Box *a, FILE * trace);
GF_Err moov_dump(GF_Box *a, FILE * trace);
GF_Err mvhd_dump(GF_Box *a, FILE * trace);
GF_Err mdhd_dump(GF_Box *a, FILE * trace);
GF_Err vmhd_dump(GF_Box *a, FILE * trace);
GF_Err smhd_dump(GF_Box *a, FILE * trace);
GF_Err hmhd_dump(GF_Box *a, FILE * trace);
GF_Err nmhd_dump(GF_Box *a, FILE * trace);
GF_Err stbl_dump(GF_Box *a, FILE * trace);
GF_Err dinf_dump(GF_Box *a, FILE * trace);
GF_Err url_dump(GF_Box *a, FILE * trace);
GF_Err urn_dump(GF_Box *a, FILE * trace);
GF_Err cprt_dump(GF_Box *a, FILE * trace);
GF_Err hdlr_dump(GF_Box *a, FILE * trace);
GF_Err iods_dump(GF_Box *a, FILE * trace);
GF_Err trak_dump(GF_Box *a, FILE * trace);
GF_Err mp4s_dump(GF_Box *a, FILE * trace);
GF_Err mp4v_dump(GF_Box *a, FILE * trace);
GF_Err mp4a_dump(GF_Box *a, FILE * trace);
GF_Err edts_dump(GF_Box *a, FILE * trace);
GF_Err udta_dump(GF_Box *a, FILE * trace);
GF_Err dref_dump(GF_Box *a, FILE * trace);
GF_Err stsd_dump(GF_Box *a, FILE * trace);
GF_Err stts_dump(GF_Box *a, FILE * trace);
GF_Err ctts_dump(GF_Box *a, FILE * trace);
GF_Err stsh_dump(GF_Box *a, FILE * trace);
GF_Err elst_dump(GF_Box *a, FILE * trace);
GF_Err stsc_dump(GF_Box *a, FILE * trace);
GF_Err stsz_dump(GF_Box *a, FILE * trace);
GF_Err stco_dump(GF_Box *a, FILE * trace);
GF_Err stss_dump(GF_Box *a, FILE * trace);
GF_Err stdp_dump(GF_Box *a, FILE * trace);
GF_Err co64_dump(GF_Box *a, FILE * trace);
GF_Err esds_dump(GF_Box *a, FILE * trace);
GF_Err minf_dump(GF_Box *a, FILE * trace);
GF_Err tkhd_dump(GF_Box *a, FILE * trace);
GF_Err tref_dump(GF_Box *a, FILE * trace);
GF_Err mdia_dump(GF_Box *a, FILE * trace);
GF_Err defa_dump(GF_Box *a, FILE * trace);
GF_Err void_dump(GF_Box *a, FILE * trace);
GF_Err ftyp_dump(GF_Box *a, FILE * trace);
GF_Err padb_dump(GF_Box *a, FILE * trace);
GF_Err stsf_dump(GF_Box *a, FILE * trace);
GF_Err gnrm_dump(GF_Box *a, FILE * trace);
GF_Err gnrv_dump(GF_Box *a, FILE * trace);
GF_Err gnra_dump(GF_Box *a, FILE * trace);
GF_Err gppa_dump(GF_Box *a, FILE * trace);
GF_Err gppv_dump(GF_Box *a, FILE * trace);
GF_Err gppc_dump(GF_Box *a, FILE * trace);
GF_Err chpl_dump(GF_Box *a, FILE * trace);
GF_Err dpin_dump(GF_Box *a, FILE * trace);

GF_Err hinf_dump(GF_Box *a, FILE * trace);
GF_Err trpy_dump(GF_Box *a, FILE * trace);
GF_Err totl_dump(GF_Box *a, FILE * trace);
GF_Err nump_dump(GF_Box *a, FILE * trace);
GF_Err npck_dump(GF_Box *a, FILE * trace);
GF_Err tpyl_dump(GF_Box *a, FILE * trace);
GF_Err tpay_dump(GF_Box *a, FILE * trace);
GF_Err maxr_dump(GF_Box *a, FILE * trace);
GF_Err dmed_dump(GF_Box *a, FILE * trace);
GF_Err dimm_dump(GF_Box *a, FILE * trace);
GF_Err drep_dump(GF_Box *a, FILE * trace);
GF_Err tmin_dump(GF_Box *a, FILE * trace);
GF_Err tmax_dump(GF_Box *a, FILE * trace);
GF_Err pmax_dump(GF_Box *a, FILE * trace);
GF_Err dmax_dump(GF_Box *a, FILE * trace);
GF_Err payt_dump(GF_Box *a, FILE * trace);
GF_Err name_dump(GF_Box *a, FILE * trace);
GF_Err rely_dump(GF_Box *a, FILE * trace);
GF_Err snro_dump(GF_Box *a, FILE * trace);
GF_Err tims_dump(GF_Box *a, FILE * trace);
GF_Err tsro_dump(GF_Box *a, FILE * trace);
GF_Err ghnt_dump(GF_Box *a, FILE * trace);
GF_Err hnti_dump(GF_Box *a, FILE * trace);
GF_Err sdp_dump(GF_Box *a, FILE * trace);
GF_Err rtpo_dump(GF_Box *a, FILE * trace);



#ifndef	GF_ISOM_NO_FRAGMENTS
GF_Err mvex_dump(GF_Box *a, FILE * trace);
GF_Err mehd_dump(GF_Box *a, FILE * trace);
GF_Err trex_dump(GF_Box *a, FILE * trace);
GF_Err moof_dump(GF_Box *a, FILE * trace);
GF_Err mfhd_dump(GF_Box *a, FILE * trace);
GF_Err traf_dump(GF_Box *a, FILE * trace);
GF_Err tfhd_dump(GF_Box *a, FILE * trace);
GF_Err trun_dump(GF_Box *a, FILE * trace);
#endif

GF_Err avcc_dump(GF_Box *a, FILE * trace);
GF_Err avc1_dump(GF_Box *a, FILE * trace);
GF_Err m4ds_dump(GF_Box *a, FILE * trace);
GF_Err btrt_dump(GF_Box *a, FILE * trace);

GF_Err ftab_dump(GF_Box *a, FILE * trace);
GF_Err tx3g_dump(GF_Box *a, FILE * trace);
GF_Err styl_dump(GF_Box *a, FILE * trace);
GF_Err hlit_dump(GF_Box *a, FILE * trace);
GF_Err hclr_dump(GF_Box *a, FILE * trace);
GF_Err krok_dump(GF_Box *a, FILE * trace);
GF_Err dlay_dump(GF_Box *a, FILE * trace);
GF_Err href_dump(GF_Box *a, FILE * trace);
GF_Err tbox_dump(GF_Box *a, FILE * trace);
GF_Err blnk_dump(GF_Box *a, FILE * trace);
GF_Err twrp_dump(GF_Box *a, FILE * trace);

/* ISMACryp dump */
GF_Err iKMS_dump(GF_Box *a, FILE * trace);
GF_Err iSFM_dump(GF_Box *a, FILE * trace);

/*MPEG-21 extensions dump*/
GF_Err meta_dump(GF_Box *a, FILE * trace);
GF_Err xml_dump(GF_Box *a, FILE * trace);
GF_Err bxml_dump(GF_Box *a, FILE * trace);
GF_Err iloc_dump(GF_Box *a, FILE * trace);
GF_Err pitm_dump(GF_Box *a, FILE * trace);
GF_Err ipro_dump(GF_Box *a, FILE * trace);
GF_Err infe_dump(GF_Box *a, FILE * trace);
GF_Err iinf_dump(GF_Box *a, FILE * trace);
GF_Err imif_dump(GF_Box *a, FILE * trace);
GF_Err ipmc_dump(GF_Box *a, FILE * trace);
GF_Err sinf_dump(GF_Box *a, FILE * trace);
GF_Err frma_dump(GF_Box *a, FILE * trace);
GF_Err schm_dump(GF_Box *a, FILE * trace);
GF_Err schi_dump(GF_Box *a, FILE * trace);



#ifdef __cplusplus
}
#endif

#endif //_GF_ISOMEDIA_DEV_H_

