/* eslint-disable */
// this is an auto generated file. This will be overwritten

export const getMassage = /* GraphQL */ `
  query GetMassage($id: ID!) {
    getMassage(id: $id) {
      id
      username
      content
    }
  }
`;
export const listMassages = /* GraphQL */ `
  query ListMassages(
    $filter: ModelMassageFilterInput
    $limit: Int
    $nextToken: String
  ) {
    listMassages(filter: $filter, limit: $limit, nextToken: $nextToken) {
      items {
        id
        username
        content
      }
      nextToken
    }
  }
`;
