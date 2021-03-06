#include "alonefile.h"

#include <cstring>


u8 AloneFile::palette[]={0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x33, 0x33, 0x3b, 0xc3, 0xbf, 0xff, 0x8f, 0xb3, 0x8f, 0xab,
              0x77, 0xab, 0xab, 0x87, 0x63, 0xff, 0x17, 0xab, 0x4b, 0x53, 0x63, 0xc7, 0x57, 0x5f, 0x57, 0x97,
              0x57, 0x57, 0xbf, 0xff, 0xff, 0x8b, 0x57, 0xaf, 0x57, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff,
              0xd7, 0xb3, 0x93, 0xcb, 0xa7, 0x87, 0xbb, 0x97, 0x7b, 0xaf, 0x8b, 0x73, 0xa3, 0x7f, 0x67, 0x97,
              0x77, 0x5f, 0x8b, 0x6b, 0x53, 0x7f, 0x5f, 0x4b, 0x73, 0x53, 0x43, 0x67, 0x4b, 0x3b, 0x5b, 0x3f,
              0x33, 0x4f, 0x37, 0x2b, 0x43, 0x2b, 0x23, 0x37, 0x23, 0x1b, 0x2b, 0x1b, 0x13, 0x1f, 0x13, 0x0f,
              0xdf, 0xb3, 0xa3, 0xcf, 0x9f, 0x8f, 0xc3, 0x8f, 0x7b, 0xb7, 0x83, 0x6b, 0xab, 0x73, 0x5b, 0x9f,
              0x67, 0x4b, 0x8f, 0x5b, 0x3f, 0x83, 0x4f, 0x33, 0x77, 0x47, 0x27, 0x6b, 0x3b, 0x1f, 0x5f, 0x33,
              0x17, 0x4f, 0x2b, 0x0f, 0x43, 0x23, 0x07, 0x37, 0x1b, 0x07, 0x2b, 0x13, 0x00, 0x1f, 0x0f, 0x00,
              0xcf, 0x6f, 0x6f, 0xc3, 0x63, 0x63, 0xb7, 0x5b, 0x5b, 0xab, 0x53, 0x4f, 0x9f, 0x4b, 0x47, 0x93,
              0x43, 0x3f, 0x87, 0x3f, 0x37, 0x7b, 0x37, 0x2f, 0x6f, 0x2f, 0x2b, 0x63, 0x2b, 0x23, 0x57, 0x23,
              0x1f, 0x4b, 0x1f, 0x17, 0x3f, 0x17, 0x13, 0x33, 0x13, 0x0f, 0x2b, 0x0f, 0x0b, 0x1f, 0x0b, 0x07,
              0x73, 0x7b, 0x6b, 0x6b, 0x73, 0x63, 0x63, 0x6f, 0x5b, 0x5b, 0x6b, 0x57, 0x53, 0x67, 0x4f, 0x4f,
              0x5f, 0x4b, 0x47, 0x5b, 0x43, 0x3f, 0x57, 0x3f, 0x3b, 0x4f, 0x3b, 0x33, 0x4b, 0x37, 0x2f, 0x47,
              0x33, 0x2b, 0x43, 0x33, 0x27, 0x3b, 0x2f, 0x23, 0x37, 0x2b, 0x1f, 0x33, 0x27, 0x1b, 0x2f, 0x27,
              0xcb, 0x33, 0x53, 0xbf, 0x2b, 0x4b, 0xb3, 0x27, 0x47, 0xa7, 0x1f, 0x43, 0x9b, 0x1b, 0x3b, 0x8f,
              0x17, 0x37, 0x83, 0x13, 0x33, 0x7b, 0x0f, 0x2f, 0x6f, 0x0b, 0x27, 0x63, 0x07, 0x23, 0x57, 0x07,
              0x1f, 0x4b, 0x00, 0x1b, 0x3f, 0x00, 0x17, 0x33, 0x00, 0x13, 0x27, 0x00, 0x0f, 0x1f, 0x00, 0x0b,
              0x7f, 0xa7, 0xab, 0x77, 0x9f, 0x9f, 0x6f, 0x97, 0x97, 0x67, 0x8f, 0x8f, 0x5f, 0x83, 0x83, 0x57,
              0x7b, 0x77, 0x4f, 0x73, 0x6f, 0x47, 0x67, 0x67, 0x3f, 0x5f, 0x5b, 0x37, 0x57, 0x4f, 0x33, 0x4b,
              0x47, 0x2b, 0x43, 0x3f, 0x23, 0x3b, 0x33, 0x1f, 0x2f, 0x2b, 0x17, 0x27, 0x23, 0x13, 0x1f, 0x1b,
              0xf3, 0xb7, 0x67, 0xe3, 0xab, 0x5f, 0xd7, 0x9f, 0x57, 0xc7, 0x93, 0x4f, 0xb7, 0x83, 0x47, 0xab,
              0x7b, 0x3f, 0x9b, 0x6f, 0x37, 0x8f, 0x63, 0x2f, 0x7f, 0x57, 0x27, 0x73, 0x4b, 0x23, 0x63, 0x43,
              0x1f, 0x57, 0x37, 0x17, 0x47, 0x2f, 0x13, 0x3b, 0x23, 0x0f, 0x2b, 0x1b, 0x0b, 0x1f, 0x13, 0x07,
              0xe3, 0x83, 0x4b, 0xd3, 0x77, 0x43, 0xc7, 0x6f, 0x3f, 0xbb, 0x63, 0x3b, 0xaf, 0x5b, 0x33, 0x9f,
              0x53, 0x2f, 0x93, 0x47, 0x2b, 0x87, 0x3f, 0x27, 0x77, 0x37, 0x23, 0x6b, 0x2f, 0x1b, 0x5f, 0x27,
              0x17, 0x53, 0x23, 0x13, 0x43, 0x1b, 0x0f, 0x37, 0x17, 0x0b, 0x2b, 0x0f, 0x07, 0x1f, 0x0b, 0x07,
              0xc3, 0x8f, 0x8f, 0xb7, 0x83, 0x83, 0xab, 0x7b, 0x7b, 0xa3, 0x6f, 0x6f, 0x97, 0x67, 0x67, 0x8f,
              0x5b, 0x5b, 0x83, 0x53, 0x53, 0x77, 0x4b, 0x4b, 0x6f, 0x43, 0x43, 0x63, 0x3b, 0x3b, 0x5b, 0x33,
              0x33, 0x4f, 0x2b, 0x2b, 0x43, 0x23, 0x23, 0x3b, 0x1f, 0x1f, 0x2f, 0x17, 0x17, 0x27, 0x13, 0x13,
              0x3b, 0x77, 0x67, 0x33, 0x6f, 0x5f, 0x2f, 0x6b, 0x5b, 0x27, 0x67, 0x57, 0x23, 0x63, 0x4f, 0x1f,
              0x5f, 0x4b, 0x1b, 0x5b, 0x47, 0x13, 0x57, 0x3f, 0x13, 0x53, 0x3b, 0x0f, 0x4b, 0x37, 0x0b, 0x47,
              0x33, 0x07, 0x43, 0x2f, 0x07, 0x3f, 0x2b, 0x00, 0x3b, 0x27, 0x00, 0x37, 0x23, 0x00, 0x33, 0x1f,
              0xc3, 0xc3, 0xb3, 0xb7, 0xb7, 0xa7, 0xab, 0xab, 0x9b, 0x9f, 0x9f, 0x8f, 0x93, 0x93, 0x83, 0x87,
              0x87, 0x7b, 0x7b, 0x7b, 0x6f, 0x73, 0x73, 0x63, 0x67, 0x67, 0x57, 0x5b, 0x5b, 0x4f, 0x4f, 0x4f,
              0x43, 0x43, 0x43, 0x3b, 0x37, 0x37, 0x2f, 0x2b, 0x2b, 0x27, 0x1f, 0x1f, 0x1b, 0x00, 0x00, 0x00,
              0x97, 0x6b, 0x6f, 0x8b, 0x63, 0x67, 0x7f, 0x5b, 0x5f, 0x77, 0x4f, 0x57, 0x6f, 0x43, 0x4f, 0x67,
              0x3b, 0x4b, 0x5f, 0x2f, 0x47, 0x57, 0x27, 0x43, 0x4f, 0x1f, 0x43, 0x47, 0x17, 0x3f, 0x3f, 0x0f,
              0x3b, 0x33, 0x0b, 0x37, 0x27, 0x07, 0x2f, 0x1b, 0x00, 0x27, 0x13, 0x00, 0x1f, 0x0b, 0x00, 0x17,
              0x8f, 0x93, 0x5f, 0x83, 0x8b, 0x53, 0x77, 0x7f, 0x47, 0x6f, 0x77, 0x3f, 0x63, 0x6f, 0x33, 0x57,
              0x67, 0x2b, 0x4b, 0x5f, 0x23, 0x43, 0x57, 0x1b, 0x3b, 0x4f, 0x17, 0x2f, 0x47, 0x0f, 0x27, 0x3f,
              0x0b, 0x1f, 0x37, 0x07, 0x17, 0x2f, 0x07, 0x0f, 0x27, 0x00, 0x0b, 0x1f, 0x00, 0x07, 0x17, 0x00,
              0xc3, 0xc3, 0xb3, 0x7f, 0xa7, 0xab, 0x77, 0x9f, 0x9f, 0x6f, 0x97, 0x97, 0x77, 0x9f, 0x9f, 0x7f,
              0xa7, 0xab, 0x6f, 0x97, 0x97, 0x67, 0x8f, 0x8f, 0x5f, 0x83, 0x83, 0x4f, 0x73, 0x6f, 0x5f, 0x83,
              0x83, 0x67, 0x8f, 0x8f, 0x3f, 0x5f, 0x5b, 0x37, 0x57, 0x4f, 0x2b, 0x43, 0x43, 0x33, 0x53, 0x4b,
              0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b,
              0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73,
              0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67, 0x7b, 0x73, 0x67};



AloneFile::AloneFile():
    mInfo({0,0,0,0,0}),mFileOffset(0),mAdditionalDescriptorSize(0),mNameBuffer(),
    mPAKFilename(0),mIndex(-1),mComprData(0),mDecomprData(0)
{
	strcpy(mNameBuffer,"?");
}

AloneFile::~AloneFile()
{
    if (mComprData) delete mComprData;
    if (mDecomprData) delete mDecomprData;
}

bool AloneFile::read(FILE* pakfile,const char* filename,unsigned int index)
{
    mPAKFilename=filename;
    mIndex=index;

    if (mComprData) delete mComprData;
    if (mDecomprData) delete mDecomprData;

    rewind(pakfile);
    fseek(pakfile,(index+1)*4,SEEK_SET);

    if (fread(&mFileOffset,4,1,pakfile)!=1)
        printf("Error reading fileOffset!\n");
  #ifdef BIG_ENDIAN_
    fileOffset = READ_LE_U32(&fileOffset);
  #endif
    fseek(pakfile,mFileOffset,SEEK_SET);

    if (fread(&mAdditionalDescriptorSize,4,1,pakfile)!=1)
        printf("Error reading additionalDescriptorSize!\n");
  #ifdef BIG_ENDIAN_ //TODO: remove ifdef and give ref to READ_LE_U32
    mAdditionalDescriptorSize = READ_LE_U32(&mAdditionalDescriptorSize);
  #endif

    readPakInfo(&mInfo,pakfile);


    if(mInfo.offset)
    {
        if (mInfo.offset>=255)
        {
            printf("Error, nameBuffer must be < 256!\n");
            return false;
        }
        //ASSERT(pakInfo.offset<256);

        if (fread(mNameBuffer,mInfo.offset,1,pakfile)!=1)
            printf("Error reading nameBuffer!\n");
  #ifdef INTERNAL_DEBUGGER
        printf("Loading %s/%s\n", filename,mNameBuffer+2);
  #endif
    }
    /*else  //useless?
    {
        fseek(pakfile,pakInfo.offset,SEEK_CUR);
    }*/

    mComprData = (u8*)malloc(mInfo.discSize);
    if (fread(mComprData,mInfo.discSize,1,pakfile)!=1)
        printf("Error reading data!\n");

    switch(mInfo.compressionFlag)
    {
    case 0:
      {
        mInfo.uncompressedSize=mInfo.discSize;
        mDecomprData = (u8 *) malloc(mInfo.uncompressedSize);
        memcpy (mDecomprData,mComprData,mInfo.uncompressedSize);

        break;
      }
    case 1:
      {
        mDecomprData = (u8 *) malloc(mInfo.uncompressedSize);
        PAK_explode(mComprData, mDecomprData, mInfo.discSize, mInfo.uncompressedSize, mInfo.info5);
        break;
      }
    case 4:
      {
        mDecomprData = (u8 *) malloc(mInfo.uncompressedSize);
        PAK_deflate(mComprData, mDecomprData, mInfo.discSize, mInfo.uncompressedSize);
        break;
      }
    }

    if (fread(&mTailingBytes,sizeof(mTailingBytes),1,pakfile)!=1) //what are these bytes???
        printf("Error reading tailing bytes!\n");

    return true;
}

void AloneFile::print()
{
    printf("File %s:%d ",mPAKFilename,mIndex);
    printf("fileOffset: %X ",mFileOffset);
    printf("additionalDescriptorSize: %X ",mAdditionalDescriptorSize);
    printf("discSize: %X ",mInfo.discSize);
    printf("uncompressedSize: %X ",mInfo.uncompressedSize);
    printf("compressionFlag: %X ",mInfo.compressionFlag);
    printf("info5: %X ",mInfo.info5);
    printf("offset: %X ",mInfo.offset);
    printf("nameBuffer: %s\n",mNameBuffer);
}

bool AloneFile::exportAsBMP(u32 offset, u32 width, u8* palette)
{
    char bufferNameBMP[256+9];
    sprintf(bufferNameBMP,"%s_%d.BMP",mPAKFilename,mIndex);
    printf("Export into %s\n",bufferNameBMP);

    if ((mInfo.uncompressedSize-offset)%width!=0)
    {
        printf("Seems not to be a %d pixel width image.\n",width);
        return false;
    }
    u32 height=(mInfo.uncompressedSize-offset)/width;
    printf("Image height seemes to be %d.\n",height);
    saveBMP(bufferNameBMP, mDecomprData+offset, palette, width, height);

    return true;
}

bool AloneFile::exportUncompressed(const char *outfilename)
{
    printf("Export into %s\n",outfilename);
    FILE* fileHandle;
    fileHandle = fopen(outfilename,"wb");

    fwrite(mDecomprData,mInfo.uncompressedSize,1,fileHandle);

    fclose(fileHandle);
    return true;
}


bool AloneFile::exportCompressed(const char *outfilename)
{
    if (mComprData)
    {
        printf("Export into %s\n",outfilename);
        FILE* fileHandle;
        fileHandle = fopen(outfilename,"wb");

        fwrite(mComprData,mInfo.discSize,1,fileHandle);

        fclose(fileHandle);
        return true;
    }else{
        printf("Error, file %l not compressed.\n",this->mIndex);
        return true;
    }
}
