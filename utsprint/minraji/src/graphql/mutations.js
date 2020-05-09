/* eslint-disable */
// this is an auto generated file. This will be overwritten

export const createMassage = /* GraphQL */ `
  mutation CreateMassage(
    $input: CreateMassageInput!
    $condition: ModelMassageConditionInput
  ) {
    createMassage(input: $input, condition: $condition) {
      id
      username
      content
    }
  }
`;
export const updateMassage = /* GraphQL */ `
  mutation UpdateMassage(
    $input: UpdateMassageInput!
    $condition: ModelMassageConditionInput
  ) {
    updateMassage(input: $input, condition: $condition) {
      id
      username
      content
    }
  }
`;
export const deleteMassage = /* GraphQL */ `
  mutation DeleteMassage(
    $input: DeleteMassageInput!
    $condition: ModelMassageConditionInput
  ) {
    deleteMassage(input: $input, condition: $condition) {
      id
      username
      content
    }
  }
`;
