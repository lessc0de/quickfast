// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#ifdef _MSC_VER
# pragma once
#endif
#ifndef FIELDOPARCANOP_H
#define FIELDOPARCANOP_H
#include "FieldOp.h"
namespace QuickFAST{
  namespace Codecs{
    /// @brief Dispatch to the appropriate method in a FieldInstruction when no operator is specified.
    class QuickFAST_Export FieldOpArcaNop : public FieldOp
    {
    public:
      virtual bool usesPresenceMap(bool mandatory)const
      {
        return true;
      }
      virtual bool usesDictionary() const
      {
        return false;
      }

      virtual bool decode(
        const Codecs::FieldInstruction & instruction,
        Codecs::DataSource & source,
        Codecs::PresenceMap & pmap,
        Codecs::Decoder & decoder,
        Messages::DecodedFields & fieldSet) const
      {
        if(pmap.checkNextField())
        {
          return instruction.decodeNop(source, pmap, decoder, fieldSet);
        }
        else
        {
          return true;
        }
      }

      virtual void encode(
        const Codecs::FieldInstruction & instruction,
        Codecs::DataDestination & destination,
        Codecs::PresenceMap & pmap,
        Codecs::Encoder & encoder,
        const Messages::FieldSet & fieldSet) const
      {
        pmap.setNextField(true);
        return instruction.encodeNop(destination, pmap, encoder, fieldSet);
      }

      virtual void setDefaultValue(
        Codecs::FieldInstruction & instruction) const
      {
      }
    };
  }
}
#endif // FIELDOPARCANOP_H