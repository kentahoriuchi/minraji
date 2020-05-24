/* eslint-disable */
// this is an auto generated file. This will be overwritten

export const createMessage = /* GraphQL */ `
  mutation CreateMessage(
    $input: CreateMessageInput!
    $condition: ModelMessageConditionInput
  ) {
    createMessage(input: $input, condition: $condition) {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const updateMessage = /* GraphQL */ `
  mutation UpdateMessage(
    $input: UpdateMessageInput!
    $condition: ModelMessageConditionInput
  ) {
    updateMessage(input: $input, condition: $condition) {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const deleteMessage = /* GraphQL */ `
  mutation DeleteMessage(
    $input: DeleteMessageInput!
    $condition: ModelMessageConditionInput
  ) {
    deleteMessage(input: $input, condition: $condition) {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const createUser = /* GraphQL */ `
  mutation CreateUser(
    $input: CreateUserInput!
    $condition: ModelUserConditionInput
  ) {
    createUser(input: $input, condition: $condition) {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const updateUser = /* GraphQL */ `
  mutation UpdateUser(
    $input: UpdateUserInput!
    $condition: ModelUserConditionInput
  ) {
    updateUser(input: $input, condition: $condition) {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const deleteUser = /* GraphQL */ `
  mutation DeleteUser(
    $input: DeleteUserInput!
    $condition: ModelUserConditionInput
  ) {
    deleteUser(input: $input, condition: $condition) {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const createRoom = /* GraphQL */ `
  mutation CreateRoom(
    $input: CreateRoomInput!
    $condition: ModelRoomConditionInput
  ) {
    createRoom(input: $input, condition: $condition) {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
export const updateRoom = /* GraphQL */ `
  mutation UpdateRoom(
    $input: UpdateRoomInput!
    $condition: ModelRoomConditionInput
  ) {
    updateRoom(input: $input, condition: $condition) {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
export const deleteRoom = /* GraphQL */ `
  mutation DeleteRoom(
    $input: DeleteRoomInput!
    $condition: ModelRoomConditionInput
  ) {
    deleteRoom(input: $input, condition: $condition) {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
